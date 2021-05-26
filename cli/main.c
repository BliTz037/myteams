/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** main
*/

#include "cli.h"

static char *commmand_str[] =
    {"/login", "/logout", "/user", "/send",
    "/messages", "/subscribe", "/subscribed",
    "/unsubscribe", "/create", "/list", "/info", "/use"};

int print_help(char *av)
{
    printf("USAGE: %s ip port\n\n", av);
    printf("\tip is the server ip address on which the server socket listens\n"
    );
    printf("\tport is the port number on which the server socket listens\n");
    return (0);
}

void display(request_t *msg)
{
    printf("COMMAND : '%s'\n", commmand_str[msg->command]);
    printf("\tlogin.username: '%s'\n", msg->login.username);
    printf("\tuser.user_uuid: '%s'\n", msg->user.user_uuid);
    printf("\tsend.user_uuid: '%s'\n\t\tsend.body: '%s'\n",
    msg->send.user_uuid, msg->send.body);
    printf("\tmessage.user_uuid: '%s'\n", msg->message.user_uuid);
    printf("\tsubcribe.team_uuid: '%s'\n\n", msg->subcribe.team_uuid);
    printf("CREATE\n");
    printf("\tcreate team_name: '%s'\n", msg->create.teams.team_name);
    printf("\tcreate team_description: '%s'\n",
    msg->create.teams.team_description);
    printf("\tcreate channel_name: '%s'\n", msg->create.channel.channel_name);
    printf("\tcreate channel_description: '%s'\n",
    msg->create.channel.channel_description);
    printf("\tcreate thread_name: '%s'\n", msg->create.thread.thread_title);
    printf("\tcreate thread_description: '%s'\n",
    msg->create.thread.thread_message);
    printf("\tcreate messages_body: '%s'\n", msg->create.messasge.body);
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return print_help(av[0]);
    if (ac != 3)
        return (84);
    return client_loop(av[1], atoi(av[2]));
}