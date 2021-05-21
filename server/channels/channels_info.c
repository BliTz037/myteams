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

static void channels_teams_info(teams_t *team, int fd)
{   
    response_t *response = malloc(sizeof(response_t));
    int j = 0;

    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strlen(team->channels[i].name) > 0)
        {
            response->infos.channel[j] = team->channels[i];
            j++;
        }
    }
    response->code = 200;
    write(fd, &response, sizeof(response_t));
    free(response);
}

void get_channel_info(server_t *server, info_t *info, int client)
{
    for(int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(info->channel.team_uuid, server->teams[i].uuid) == 0)
        {
            channels_teams_info(&server->teams[i],
            server->clients[client].socket);
            return;
        }
    }
    request_error(server->clients[client].socket, 404);
}