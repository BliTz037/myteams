/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** send
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include "logging_server.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static void set_private_message(private_message_t *private,
char *body)
{
    for (int i = 0; i != MAX_PM; i++)
    {
        if (strlen(private->messages[i].message) == 0)
        {
            strcpy(private->messages[i].message, body);
            private->messages[i].timestamp = time(NULL);
            return;
        }
    }
}

static void set_message(client_t *client,
char *other_uuid, char *body)
{
    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strcmp(client->private_messages[i].user_uuid, other_uuid) == 0)
        {
            set_private_message(&client->private_messages[i], body);
            return;
        }
    }
    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strlen(client->private_messages[i].user_uuid) == 0)
        {
            memcpy(&client->private_messages[i].user_uuid,
            other_uuid, UUID_SIZE);
            set_private_message(&client->private_messages[i], body);
            return;
        }
    }
}

static void private_message_response(int fd, char *uuid, char *body)
{
    response_t *response = malloc(sizeof(response_t));

    response->code = 200;
    response->command = SEND;
    memcpy(response->message.user_uuid, uuid, UUID_SIZE);
    memcpy(response->message.messages[0].message, body, MAX_BODY_LENGTH);
    write(fd, response, sizeof(response_t));
    free(response);
}

void my_send(server_t *server, int client, request_t *request)
{
    send_t *send = &request->send;

    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strcmp(send->user_uuid, server->clients[i].uuid) == 0)
        {
            set_message(&server->clients[client], send->user_uuid, send->body);
            set_message(&server->clients[i], server->clients[client].uuid,
            send->body);
            private_message_response(server->clients[i].socket,
            server->clients[client].uuid, send->body);
            server_event_private_message_sended(server->clients[client].uuid,
            send->user_uuid, send->body);
            return;
        }
    }
    request_404_error(server->clients[client].socket, send->user_uuid, USER);
}