/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** user
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void users_info(server_t *server, int fd)
{
    response_t *response = malloc(sizeof(response_t));
    int j = 0;

    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strlen(server->clients[i].uuid) > 0)
        {
            strcpy(response->user.users[j].uuid, server->clients[i].uuid);
            strcpy(response->user.users[j].name, server->clients[i].name);
            response->user.users[j].status =
            server->clients[i].loged == 1 ? 0 : 1;
            j++;
        }
    }
    response->code = 200;
    response->command = USER;
    write(fd, response, sizeof(response_t));
    free(response);
}

static void user_info(server_t *server, int fd ,char *uuid)
{
    response_t *response;

    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strcmp(server->clients[i].uuid, uuid) != 0)
        {
            response = malloc(sizeof(response_t));
            strcpy(response->user.users[0].uuid, server->clients[i].uuid);
            strcpy(response->user.users[0].name, server->clients[i].name);
            response->user.users[0].status =
            server->clients[i].loged == 1 ? 0 : 1;
            response->code = 200;
            response->command = USER;
            write(fd, response, sizeof(response_t));
            free(response);
            return;
        }
    }
    request_code(fd, 404);
}

void user(server_t *server, int client, request_t *request)
{
    user_t *user_response = &request->user;

    if (strlen(user_response->user_uuid) == 0)
        users_info(server, server->clients[client].socket);
    else
        user_info(server, server->clients[client].socket,
        user_response->user_uuid);
}