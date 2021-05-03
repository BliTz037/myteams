/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** main
*/

#include "server.h"

int print_help(char *av)
{
    printf("USAGE: %s port\n\n", av);
    printf("\tport is the port number on which the server socket listens\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (strcmp(av[1], "-help") == 0)
        return print_help(av[0]);
    return (0);
}