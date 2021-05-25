/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** channel
*/

#include "server.h"
#include "communication.h"
#include "logging_server.h"
#include "server_request.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void add_channel_response(response_t *response,
channel_t *channel)
{
    response->code = 200;
    response->command = CREATE;
    strcpy(response->infos.channel[0].channel_description, channel->description);
    strcpy(response->infos.channel[0].channel_name, channel->name);
    memcpy(response->infos.channel[0].team_uuid, channel->uuid, UUID_SIZE);
}

static void add_channel_in_team(teams_t *team, channel_manipulation_t *channel,
int fd)
{
    char *uuid = generate_uuid();
    response_t *response = malloc(sizeof(response_t));

    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strlen(team->channels[i].name) == 0)
        {
            strcpy(team->channels[i].name, channel->channel_name);
            strcpy(team->channels[i].description, channel->channel_description);
            memcpy(team->channels[i].uuid, uuid, UUID_SIZE);
            server_event_channel_created(team->uuid, uuid, team->channels[i].name);
            add_channel_response(response, &team->channels[i]);
            write(fd, response, sizeof(response_t));
            free(uuid);
            free(response);
            return;
        }
    }
}

void add_channel(server_t *server, create_t *create, int client)
{
    for(int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(create->channel.team_uuid, server->teams[i].uuid) == 0)
        {
            if (check_subscribed_request(server->clients[client].socket,
            server->clients[client].uuid, &server->teams[i]) == -1)
                return;
            add_channel_in_team(&server->teams[i], &create->channel,
            server->clients[client].socket);
            return;
        }
    }
    request_404_error(server->clients[client].socket,
    create->channel.team_uuid, TEAMS);
}