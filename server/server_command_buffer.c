/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server_command_buffer
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"
#include "server.h"


char *get_command_buffer(server_t *server, int client, char input[1024])
{
    char *command;
    int buffer_size;

    strcat(server->clients[client].command, input);
    buffer_size = strlen(server->clients[client].command);
    if (server->clients[client].command[buffer_size - 1] != '\n'
    || server->clients[client].command[buffer_size - 2] != '\r')
        return NULL;
    command = malloc(buffer_size);
    for (int i = 0; i != buffer_size; i++)
        command[i] = server->clients[client].command[i];
    memset(server->clients[client].command, 0,
    sizeof(server->clients[client].command));
    return command;
}