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

    printf(">");
    lineSize = getline(&line, &len, stdin);
    if (lineSize == -1)
        return NULL;
    return (line);
}

char **str_to_word_array(char *src, char *separator)
{
    char *str_token = strtok(src, " ");
    char **tab = NULL;
    int a = 0;

    for (; str_token != NULL; str_token = strtok(NULL, separator)) {
        if (str_token[strlen(str_token) - 1] != '\n' &&
        str_token[strlen(str_token) - 1] != ' ') {
            tab = reallocarray(tab, (a + 2), sizeof(char *));
            tab[a] = malloc(sizeof(str_token));
            tab[a] = strdup(str_token);
            a++;
        }
    }
    tab[a] = NULL;
    return (tab);
}

int fill_request_struct(char *command, request_t *msg)
{
    int i = 0;
    char **tab = str_to_word_array(command, "[]");
    void (*parser[])(char **, request_t *) =
    {command_login, command_logout, command_user, command_send,
    command_messages,command_subscribe, command_subscribed,
    command_unsubscribed,command_create, command_list, command_info};

    for (i = 0; commmand_str[i] != NULL && strcmp(tab[0], commmand_str[i]) != 0; i++);
    if (commmand_str[i] != NULL) {
        parser[i](tab + 1, msg);
        return (1);
    }
    return (0);
}