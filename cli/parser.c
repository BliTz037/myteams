/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** parser
*/

#include "cli.h"
#include "communication.h"

static char *commmand_str[] =
    {"/login", "/logout", "/user", "/users", "/send",
    "/messages", "/subscribe", "/subscribed",
    "/unsubscribe", "/create", "/list", "/info", "/use", "/help"};

int get_context(cli_t *cli)
{
    if (strcmp(cli->context.team_uuid, "\0") == 0)
        return (NOTHING);
    if (strcmp(cli->context.channel_uuid, "\0") == 0)
        return (TEAMS);
    if (strcmp(cli->context.thread_uuid, "\0") == 0)
        return (CHANNEL);
    return (THREAD);
}

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

void translate_response(response_t *res)
{
    void (*response[])(response_t *) = {response_login,
    response_logout, response_user, response_users, response_send,
    response_messages, response_subscribe, response_subscribed,
    response_unsubscribed, response_create, response_list, response_info};

    if (res->code >= 200 && res->code <= 299)
        response[res->command](res);
    else
        manage_error_response(res);
}

int fill_request_struct(char *command, request_t *msg, cli_t *cli)
{
    int len = 0;
    int status = 0;
    char **tab = str_to_word_array(command, " \n", &len);
    int (*parser[])(char **, request_t *, cli_t *) = {command_login,
    command_logout, command_user, command_users, command_send, command_messages,
    command_subscribe, command_subscribed, command_unsubscribed,
    command_create, command_list, command_info, command_use, command_help};

    for (size_t i = 0; commmand_str[i] != NULL && len >= 1; i++) {
        if (strcmp(tab[0], commmand_str[i]) == 0) {
            status = parser[i](tab + 1, msg, cli);
            free_world_arr(tab, len);
            return (status);
        }
    }
    printf("Unknown command\n");
    free_world_arr(tab, len);
    return (0);
}