/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** parser
*/

#include "cli.h"
#include "communication.h"

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
        tab[i] = strdup(token);
        i++;
        tab = realloc(tab, (sizeof(char *) * (i + 1)));
        token = strtok(NULL, delim);
    }
    tab[i] = NULL;
    *len = i;
    return tab;
}

int try_use_command(char **tab, cli_t *cli)
{
    if (strcmp(tab[0], "/use") != 0)
        return (0);
    if (tab[1] != NULL && tab[2] == NULL)
        strcpy(cli->context.team_uuid, tab[1]);
    else if (tab[1] != NULL && tab[2] != NULL && tab[3] == NULL) {
        strcpy(cli->context.team_uuid, tab[1]);
        strcpy(cli->context.channel_uuid, tab[2]);
    } else if (tab[1] != NULL && tab[2] != NULL && tab[3] != NULL) {
        strcpy(cli->context.team_uuid, tab[1]);
        strcpy(cli->context.channel_uuid, tab[2]);
        strcpy(cli->context.thread_uuid, tab[3]);
    }
    return (1);
}

int fill_request_struct(char *command, request_t *msg, cli_t *cli)
{
    void (*parser[])(char **, request_t *) =
    {command_login, command_logout, command_user, command_send,
    command_messages,command_subscribe, command_subscribed,
    command_unsubscribed, command_create, command_list, command_info};
    int len = 0;
    char **tab = str_to_word_array(command, " \"\n", &len);

    for (size_t i = 0; commmand_str[i] != NULL && len >= 1; i++) {
        if (strcmp(tab[0], commmand_str[i]) == 0) {
            parser[i](tab + 1, msg);
            free_world_arr(tab, len);
            return (1);
        }
    }
    if (try_use_command(tab, cli) == 1) {
        free_world_arr(tab, len);
        return (1);
    } else 
        printf("Unknown command\n");
    free_world_arr(tab, len);
    return (0);
}