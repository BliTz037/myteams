/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** main
*/

#include "cli.h"
#include "communication.h"

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
    printf("\tuser.user_uuid: '%d'\n", msg->user.user_uuid);
    printf("\tsend.user_uuid: '%d'\n\t\tsend.body: '%s'\n",
    msg->send.user_uuid, msg->send.body);
    printf("\tmessage.user_uuid: '%d'\n", msg->message.user_uuid);
    printf("\tsubcribe.team_uuid: '%d'\n", msg->subcribe.team_uuid);

}

int send_message(request_t *msg)
{
    if (msg != NULL) {
        display(msg);
        return (1);
    }
    return (0);
}


int client_loop(void)
{
    request_t *msg = malloc(sizeof(request_t));

    while (1) {
        if (fill_request_struct(get_command_line(), msg) == 1)
            send_message(msg);
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (strcmp(av[1], "-help") == 0)
        return print_help(av[0]);
    client_loop();
    return (0);
}