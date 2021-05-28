/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** teams_info
*/

#include "server.h"
#include "communication.h"
#include <string.h>
#include "logging_server.h"
#include "server_request.h"
#include <uuid/uuid.h>
#include <stdlib.h>
#include <unistd.h>

void get_teams_info(server_t *server, int client, info_t *info)
{
    response_t *response;

    for (int i = 0; i != MAX_TEAMS; i++) {
        if (strcmp(server->teams[i].uuid, info->channel.team_uuid) == 0) {
            response = malloc(sizeof(response_t));
            strcpy(response->infos.teams[0].team_name, server->teams[i].name);
            memcpy(response->infos.teams[0].team_uuid,
            server->teams[i].uuid, UUID_SIZE);
            strcpy(response->infos.teams[0].team_description,
            server->teams[i].description);
            response->code = 200;
            response->command = INFO;
            response->infos.type = TEAMS;
            write(server->clients[client].socket, response,
            sizeof(response_t));
            free(response);
            return;
        }
    }
    request_404_error(server->clients[client].socket,
    info->channel.team_uuid, TEAMS);
}