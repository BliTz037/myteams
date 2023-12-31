/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** main
*/

#include "cli.h"

int print_help(char *av)
{
    printf("USAGE: %s ip port\n\n", av);
    printf("\tip is the server ip address on which the server socket listens\n"
    );
    printf("\tport is the port number on which the server socket listens\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return print_help(av[0]);
    if (ac != 3)
        return (84);
    return client_loop(av[1], atoi(av[2]));
}