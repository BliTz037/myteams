/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server
*/

#include "server.h"
#include "communication.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "logging_server.h"
#include "server_request.h"

static void get_client_request(server_t *server, int sd, int client)
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

static int select_socket(server_t *server)
{
    int max_sd = server->control_socket;
    int sd;

    FD_ZERO(&server->readfds);
    FD_SET(server->control_socket, &server->readfds);
    for (int i = 0; i < MAX_CLIENTS ; i++)
    {
        sd = server->clients[i].socket;
        if (sd > 0)
            FD_SET(sd, &server->readfds);
        if (sd > max_sd)
            max_sd = sd;
    }
    if (select(max_sd + 1, &server->readfds, NULL, NULL, NULL) < 0)
        return -1;
    return 0;
}

static int handle_existing_connection(server_t *server)
{
    int sd;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        sd = server->clients[i].socket;
        if (!FD_ISSET(sd, &server->readfds))
            continue;
        get_client_request(server, sd, i);
    }
    return 0;
}

static int handle_new_connection(server_t *server)
{
    int new_socket;

    if ((new_socket = accept(server->control_socket,
    (struct sockaddr *)&server->address,
    (socklen_t *)&server->address_size)) < 0)
        return -1;
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        if (server->clients[i].socket == 0 && strlen(server->clients[i].name) == 0)
        {
            server->clients[i].socket = new_socket;
            break;
        }
    }
    return 0;
}

int launch_server(int port)
{
    server_t *server = malloc(sizeof(server_t));
    int check_connection;

    if (init_server(server, port) == -1)
        return -1;
    while (1) {
        if (select_socket(server) == -1)
            return -1;
        if (FD_ISSET(server->control_socket, &server->readfds))
            check_connection = handle_new_connection(server);
        if (check_connection == -1)
            return -1;
        check_connection = handle_existing_connection(server);
        if (check_connection == 1)
            return 0;
        else if (check_connection == -1)
            return -1;
    }
    return 0;
}