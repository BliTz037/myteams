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

void get_current_logged_infos(server_t *server, int client)
{
    response_t *response = malloc(sizeof(response_t));

    memcpy(response->user.users[0].uuid, server->clients[client].uuid,
    UUID_SIZE);
    strcpy(response->user.users[0].name, server->clients[client].name);
    response->user.users[0].status = 1;
    response->code = 200;
    response->command = USERS;
    write(server->clients[client].socket, response, sizeof(response_t));
    free(response);
}

static void users_info(server_t *server, int fd)
{
    response_t *response = malloc(sizeof(response_t));
    int j = 0;

    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strlen(server->clients[i].uuid) > 0)
        {
            memcpy(response->user.users[j].uuid, server->clients[i].uuid,
            UUID_SIZE);
            strcpy(response->user.users[j].name, server->clients[i].name);
            response->user.users[j].status =
            server->clients[i].loged == 1 ? 1 : 0;
            j++;
        }
    }
    response->code = 200;
    response->command = USERS;
    write(fd, response, sizeof(response_t));
    free(response);
}

static void user_info(server_t *server, int fd , char *uuid)
{
    response_t *response;

    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strcmp(server->clients[i].uuid, uuid) == 0)
        {
            response = malloc(sizeof(response_t));
            memcpy(response->user.users[0].uuid,
            server->clients[i].uuid, UUID_SIZE);
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
    request_404_error(fd, uuid, USER);
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