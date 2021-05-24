/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** parser
*/

#include "cli.h"
#include "communication.h"

static char *commmand_str[] =
    {"/login", "/logout", "/user", "/send",
    "/messages", "/subscribe", "/subscribed",
    "/unsubscribe", "/create", "/list", "/info", "/use"};

char *get_command_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;

    lineSize = getline(&line, &len, stdin);
    if (lineSize == -1)
        return NULL;
    return (line);
}

void free_world_arr(char **tab, const int len)
{
    for (int i = 0; i < len; i++)
        if (tab[i] != NULL)
            free(tab[i]);
    free(tab);
}

char **str_to_word_array(char *str, const char *delim, int *len)
{
    char **tab = malloc(sizeof(char *));
    char *token = strtok(str, delim);
    int i = 0;

    if (!str || !token || !delim)
        return NULL;
    while (token != NULL) {
        if (strcmp(token, " ") != 0) {
            tab[i] = strdup(token);
            i++;
            tab = realloc(tab, (sizeof(char *) * (i + 1)));
        }
        token = strtok(NULL, "\"\n");
        printf("'%s'\n", token);
    }
    tab[i] = NULL;
    *len = i;
    return tab;
}

int fill_request_struct(char *command, request_t *msg, cli_t *cli)
{
    int (*parser[])(char **, request_t *, cli_t *) = {command_login,
    command_logout, command_user, command_send, command_messages,
    command_subscribe, command_subscribed, command_unsubscribed,
    command_create, command_list, command_info, command_use};
    int len = 0;
    char **tab = str_to_word_array(command, " \n", &len);

    for (size_t i = 0; commmand_str[i] != NULL && len >= 1; i++) {
        if (strcmp(tab[0], commmand_str[i]) == 0) {
            parser[i](tab + 1, msg, cli);
            free_world_arr(tab, len);
            return (1);
        }
    }
    printf("Unknown command\n");
    free_world_arr(tab, len);
    return (0);
}