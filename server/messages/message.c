/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** message
*/

#include "server.h"
#include "communication.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>

static void addMessageInThread(thread_t *thread,
message_manipulation_t *message_info, char *user_uuid)
{
    for (int i = 0; i != MAX_COMMENTS; i++)
    {
        if (strlen(thread->comments[i]) == 0)
        {
            strcpy(thread->comments[i], message_info->body);
            server_event_reply_created(message_info->thread_uuid,
            user_uuid, message_info->body);
            return;
        }
    }
}

static void findThread(channel_t *channel,
message_manipulation_t *message_info, char *user_uuid)
{

    for (int i = 0; MAX_THREADS; i++)
    {
        if (strcmp(channel->threads[i].uuid, message_info->thread_uuid) == 0)
        {
            addMessageInThread(&channel->threads[i], message_info, user_uuid);
            return;
        }
    }
}

static void findChannel(teams_t *team,
message_manipulation_t *message_info, char *user_uuid)
{
    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strcmp(message_info->channel_uuid, team->channels[i].uuid))
        {
            findThread(&team->channels[i], message_info, user_uuid);
            return;
        }
    }
}

void addMessage(server_t *server, create_t *create, int client)
{
    message_manipulation_t *message_info = &create->messasge;

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(message_info->team_uuid, server->teams[i].uuid))
        {
            findChannel(&server->teams[i], message_info, server->clients[client].uuid);
            return;
        }
    }
}