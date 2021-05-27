/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** channels_info
*/

#include "server.h"
#include "communication.h"
#include "logging_server.h"
#include "server_request.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void channels_teams_info(teams_t *team, int fd, info_t *info)
{
    response_t *response;

    for (int i = 0; i != MAX_CHANNEL; i++) {
        if (strcmp(team->channels[i].uuid, info->thread.channel_uuid) != 0) {
            response = malloc(sizeof(response_t));
            strcpy(response->infos.channel[0].channel_description,
            team->channels[i].description);
            strcpy(response->infos.channel[0].channel_name,
            team->channels[i].name);
            memcpy(response->infos.channel[0].team_uuid,
            team->channels[i].uuid, UUID_SIZE);
            response->code = 200;
            response->command = LIST;
            response->infos.type = CHANNEL;
            write(fd, response, sizeof(response_t));
            free(response);
        }
    }
    request_404_error(fd, info->thread.channel_uuid, CHANNEL);
}

void get_channel_info(server_t *server, info_t *info, int client)
{
    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(info->channel.team_uuid, server->teams[i].uuid) == 0)
        {
            if (check_subscribed_request(server->clients[client].socket,
            server->clients[client].uuid, &server->teams[i]) == -1)
                return;
            channels_teams_info(&server->teams[i],
            server->clients[client].socket, info);
            return;
        }
    }
    request_404_error(server->clients[client].socket,
    info->channel.team_uuid, TEAMS);
}