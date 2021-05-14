/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server_user_connection
*/

#include "server.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void close_connection(server_t *server, int fd, int client)
{
    char *message = "221 Service closing control connection.\n";
    write(fd, message, strlen(message));
    close(fd);
    server->clients[client].socket = 0;
    memset(server->clients[client].command, 0, 1024);
}