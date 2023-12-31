/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** main
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int print_help(char *av)
{
    printf("USAGE: %s port\n\n", av);
    printf("\tport is the port number on which the server socket listens\n");
    return (0);
}

int main(int ac, char **av)
{
    int port;
    server_t *server;

    if (ac != 2)
        return (84);
    if (strcmp(av[1], "-help") == 0)
        return print_help(av[0]);
    if ((port = atoi(av[1])) <= 0)
        return 84;
    server = malloc(sizeof(server_t));
    load_data("save.dat", server);
    if (launch_server(server, port) == -1)
        return 84;
    save_data("save.dat", server);
    free(server);
    return (0);
}