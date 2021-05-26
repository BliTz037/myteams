/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** request
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int check_subscribed_request(int fd, char *user_uuid, teams_t *team)
{
    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strcmp(team->subscribed_users[i].uuid, user_uuid) == 0)
            return 0;
    }
    request_code(fd, 403);
    return -1;
}

void request_code(int fd, int code)
{
    response_t *response = malloc(sizeof(response_t));

    response->code = code;

    write(fd, response, sizeof(response_t));
    free(response);
}

void request_404_error(int fd, char *uuid, service_type type)
{
    response_t *response = malloc(sizeof(response_t));

    response->code = 404;
    memcpy(response->error_404.uuid, uuid, UUID_SIZE);
    response->error_404.type = type;
    write(fd, response, sizeof(response_t));
    free(response);
}

void handle_request(server_t *server, int client, request_t *request)
{
    if (request->command != LOGIN && server->clients[client].loged == -1)
    {
        request_code(server->clients[client].socket, 403);
        return;
    }
    for (int i = 0; i != sizeof(request_list) / sizeof(*request_list); i++)
    {
        if (request->command == request_list[i].command)
        {
            request_list[i].fct(server, client, request);
            return;
        }
    }
}

void get_client_request(server_t *server, int sd, int client)
{
    request_t *request = malloc(sizeof(request_t));

    if (read(sd, request, sizeof(request_t)) <= 0)
    {
        close_connection(server, sd, client);
        return;
    }
    handle_request(server, client, request);
    free(request);
}