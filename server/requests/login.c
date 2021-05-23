/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** login
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void log_response(int fd, int code, char *username, char *uuid)
{
    response_t *response = malloc(sizeof(response_t));

    response->code = code;

    strcpy(response->user.users[0].name, username);
    strcpy(response->user.users[0].uuid, uuid);
    printf("send response of size %ld\n", sizeof(response_t));
    write(fd, response, sizeof(response_t));
    free(response);
}

static void login_new_user(server_t *server, int client, request_t *request)
{
    char *uuid = generate_uuid();

    strcpy(server->clients[client].name, request->login.username);
    strcpy(server->clients[client].uuid, uuid);
    server->clients[client].loged = 1;
    log_response(server->clients[client].socket, 201,
    server->clients[client].name, server->clients[client].uuid);
    server_event_user_created(server->clients[client].uuid,
    server->clients[client].name);
    free (uuid);
}

void login(server_t *server, int client, request_t *request)
{
    if (server->clients[client].loged == 1) {
        request_code(server->clients[client].socket, 405);
        return;
    }
    for (int i = 0; i != MAX_CLIENTS; i++) {
        if (strcmp(server->clients[i].name, request->login.username) == 0) {
            server->clients[i].socket = server->clients[client].socket;
            server->clients[i].loged = 1;
            if (i != client)
                server->clients[client].socket = 0;
            log_response(server->clients[i].socket, 200,
            server->clients[i].name, server->clients[i].uuid);
            server_event_user_logged_in(server->clients[i].uuid);
            return;
        }
    }
    login_new_user(server, client, request);
}

void logout(server_t *server, int client, request_t *request)
{
    (void)request;
    server->clients[client].loged = -1;
    log_response(server->clients[client].socket, 200,
    server->clients[client].name, server->clients[client].uuid);
    server_event_user_logged_out(server->clients[client].uuid);
}