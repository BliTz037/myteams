/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server
*/

#include "server.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static int handle_command_buffer(server_t *server, int sd, int client)
{
    char buffer[1024];
    int check_command;
    int valread;
    char *command;

    if ((valread = read(sd, buffer, sizeof(buffer))) == 0)
        close_connection(server, sd, client);
    else {
        buffer[valread] = '\0';
        command = get_command_buffer(server, client, buffer);
        if (command == NULL)
            return 0;
        check_command = handle_commands(server, command, client);
        if (check_command == 1)
            return 1;
        else if (check_command == -1)
            return -1;
        free (command);
    }
    return 0;
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
    int command_return;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        sd = server->clients[i].socket;
        if (!FD_ISSET(sd, &server->readfds))
            continue;
        command_return = handle_command_buffer(server, sd, i);
        if (command_return == 1)
            return 1;
        else if (command_return == -1)
            return -1;
    }
    return 0;
}

static int handle_new_connection(server_t *server)
{
    int new_socket;
    char *message = "220 Service ready for new user.\n";

    if ((new_socket = accept(server->control_socket,
    (struct sockaddr *)&server->address,
    (socklen_t *)&server->address_size)) < 0)
        return -1;
    write(new_socket, message, strlen(message));
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        if (server->clients[i].socket == 0)
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