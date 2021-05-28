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
    ("USAGE: %s ip port\n\n", av);
    ("\tip is the server ip address on which the server socket listens\n"
    );
    ("\tport is the port number on which the server socket listens\n");
    return (0);
}

void display(request_t *msg)
{
    // ("COMMAND : '%s'\n", commmand_str[msg->command]);
    // ("\tlogin.username: '%s'\n", msg->login.username);
    // ("\tuser.user_uuid: '%s'\n", msg->user.user_uuid);
    // ("\tsend.user_uuid: '%s'\n\t\tsend.body: '%s'\n",
    // msg->send.user_uuid, msg->send.body);
    // ("\tmessage.user_uuid: '%s'\n", msg->message.user_uuid);
    // ("\tsubcribe.team_uuid: '%s'\n\n", msg->subcribe.team_uuid);
    // ("CREATE\n");
    // ("\tcreate team_name: '%s'\n", msg->create.teams.team_name);
    // ("\tcreate team_description: '%s'\n",
    // msg->create.teams.team_description);
    // ("\tcreate channel_name: '%s'\n", msg->create.channel.channel_name);
    // ("\tcreate channel_description: '%s'\n",
    // msg->create.channel.channel_description);
    // ("\tcreate thread_name: '%s'\n", msg->create.thread.thread_title);
    // ("\tcreate thread_description: '%s'\n",
    // msg->create.thread.thread_message);
    // ("\tcreate messages_body: '%s'\n", msg->create.messasge.body);
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return print_help(av[0]);
    if (ac != 3)
        return (84);
    return client_loop(av[1], atoi(av[2]));
}