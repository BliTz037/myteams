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
    close(fd);
    server->clients[client].socket = 0;
    server->clients[client].loged = -1;
}