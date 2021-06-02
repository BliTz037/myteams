/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server_user_connection
*/

#include "server.h"
#include "logging_server.h"
#include "communication.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void close_connection(server_t *server, int fd, int client)
{
    response_t *response = malloc(sizeof(response_t));

    response->code = 200;
    response->command = LOGOUT;
    strcpy(response->user.users[0].name, server->clients[client].name);
    memcpy(response->user.users[0].uuid, server->clients[client].uuid, UUID_SIZE);
    close(fd);
    server->clients[client].socket = 0;
    if (server->clients[client].loged == 1)
        server_event_user_logged_out(server->clients[client].uuid);
    server->clients[client].loged = -1;
    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (server->clients[i].loged == 1)
            write(server->clients[i].socket, response, sizeof(response_t));
    }
    free(response);
}