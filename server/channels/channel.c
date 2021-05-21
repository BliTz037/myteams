/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** channel
*/

#include "server.h"
#include "communication.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>

static void add_channel_in_team(teams_t *team, channel_manipulation_t *channel)
{
    char *uuid = generate_uuid();

    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strlen(team->channels[i].name) == 0)
        {
            strcpy(team->channels[i].name, channel->channel_name);
            strcpy(team->channels[i].description, channel->channel_description);
            strcpy(team->channels[i].uuid, uuid);
            free(uuid);
            server_event_channel_created(team->uuid, uuid, team->channels[i].name);
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
            add_channel_in_team(&server->teams[i], &create->channel);
            return;
        }
    }
}