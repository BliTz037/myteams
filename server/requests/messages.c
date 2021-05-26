/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** messages
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include "logging_server.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void list_private_messages(int fd, private_message_t *messages)
{
    response_t *response = malloc(sizeof(response_t));
    int j = 0;

    response->code = 200;
    response->command = MESSAGES;
    memcpy(response->message.user_uuid, messages->user_uuid, UUID_SIZE);
    for (int i = 0; i != MAX_PM; i++)
    {
        if (strlen(messages->messages[i].message) > 0)
        {
            strcpy(response->message.messages[j].message,
            messages->messages[i].message);
            response->message.messages[j].timestamp =
            messages->messages[i].timestamp;
            j++;
        }
    }
    write(fd, response, sizeof(response_t));
    free(response);
}

void messages(server_t *server, int client, request_t *request)
{
    message_t *send = &request->message;

    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strcmp(send->user_uuid,
        server->clients[client].private_messages[i].user_uuid) == 0)
        {

            list_private_messages(server->clients[client].socket,
            &server->clients[client].private_messages[i]);
            return;
        }
    }
    request_404_error(server->clients[client].socket,
    send->user_uuid, MESSAGES);
}