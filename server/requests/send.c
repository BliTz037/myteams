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
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void set_private_message(private_message_t *private, send_t *send)
{

}

static void send_message_to_user(server_t *server, send_t *send,
int client, int other_client)
{
    int user_find = 0;

    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strcmp(server->clients[client].private_messages[i].user_uuid,
        send->user_uuid) == 0)
        {
            set_private_message(&server->clients[client].private_messages[i],
            send);
            user_find = 1;
            break;
        }
    }
    if (user_find == 0)
    {

    }
}

void teams_send(server_t *server, int client, request_t *request)
{
    send_t *send = &request->send;

    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strcmp(send->user_uuid, server->clients[i].uuid))
        {
            send_message_to_user(server, send, client, i);
            return;
        }
    }
    request_code(server->clients[client].socket, 404);
}