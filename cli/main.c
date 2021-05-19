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

int fill_request_struct(char *command, response_t *msg)
{

}

int send_message(request_t msg)
{

}

int client_loop(void)
{
    request_t msg;

    while (1) {
        if (fill_request_struct(get_command_line(), &msg) != NULL)
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