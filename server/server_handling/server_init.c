/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server_init
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "server.h"

static void init_clients(server_t *server)
{
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        server->clients[i].socket = 0;
        server->clients[i].loged = -1;
        memset(server->clients[i].name, 0, MAX_NAME_LENGTH);
    }
}

static int init_control_socket(server_t *server)
{
    int opt = 1;

    server->control_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server->control_socket == 0)
        return -1;
    if (setsockopt(server->control_socket,
    SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        return -1;
    return 0;
}

static int init_server_connections(server_t *server)
{
    if (bind(server->control_socket,
    (struct sockaddr *)&server->address, sizeof(server->address)) < 0)
        return -1;
    if (listen(server->control_socket, 3) < 0)
        return -1;
    return 0;
}

int init_server(server_t *server, int port)
{
    init_clients(server);
    if (init_control_socket(server) == -1)
        return -1;
    server->address.sin_family = PF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(port);
    if (init_server_connections(server) == -1)
        return -1;
    server->address_size = (sizeof(server->address));
    return 0;
}
