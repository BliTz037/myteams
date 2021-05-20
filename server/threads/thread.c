/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** thread
*/

#include "server.h"
#include "communication.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>

static void addThreadInChannel(channel_t *channel,
thread_manipulation_t *thread_info, char *user_uuid)
{
     char *uuid = generate_uuid();

    for (int i = 0; MAX_THREADS; i++)
    {
        if (strlen(channel->threads[i].title) == 0)
        {
            strcpy(channel->threads[i].title, thread_info->thread_title);
            strcpy(channel->threads[i].message, thread_info->thread_message);
            strcpy(channel->threads[i].uuid, uuid);
            server_event_thread_created(thread_info->channel_uuid,
            uuid, user_uuid, thread_info->thread_title, thread_info->thread_message);
        }
    }
}

static void findChannel(teams_t *team, thread_manipulation_t *thread_info, char *user_uuid)
{
    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strcmp(thread_info->channel_uuid, team->channels[i].uuid))
        {
            addThreadInChannel(&team->channels[i], thread_info, user_uuid);
            return;
        }
    }
}

void addThread(server_t *server, create_t *create, int client)
{
    thread_manipulation_t *thread_info = &create->thread;

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(thread_info->team_uuid, server->teams[i].uuid))
        {
            findChannel(&server->teams[i], thread_info, server->clients[client].uuid);
            return;
        }
    }
}