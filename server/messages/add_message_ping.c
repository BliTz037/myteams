/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** add_message_ping
*/

#include "server.h"
#include "communication.h"
#include "logging_server.h"
#include "server_request.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static void fill_response(response_t *response)
{
    response->code = 200;
    response->command = CREATE;
    response->create.type = MESSAGE;
    response->create.is_global_ping = 1;
}

void message_notify_all_users(server_t *server, teams_t *team,
comment_t *message, message_manipulation_t *message_info)
{
    response_t *response;

    if (message == NULL)
        return;
    response = malloc(sizeof(response_t));
    fill_response(response);
    strcpy(response->create.comments[0].body, message->body);
    memcpy(response->create.comments[0].user_uuid,
    message->user_uuid, UUID_SIZE);
    memcpy(response->create.comments[0].thread_uuid,
    message_info->thread_uuid, UUID_SIZE);
    memcpy(response->create.comments[0].team_uuid,
    message_info->team_uuid, UUID_SIZE);
    for (int i = 0; i != MAX_CLIENTS; i++) {
        if (is_subscribed_to_team(team, server->clients[i].uuid) == 1
        && server->clients[i].loged == 1) {
            write(server->clients[i].socket, response, sizeof(response_t));
        }
    }
    free(response);
}