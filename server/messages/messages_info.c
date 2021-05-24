/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** messages_info
*/

#include "server.h"
#include "communication.h"
#include "logging_server.h"
#include "server_request.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void message_info_in_thread(thread_t *thread,
message_manipulation_t *message_info, int fd, char *user_uuid)
{
    response_t *response = malloc(sizeof(response_t));
    int j = 0;

    for (int i = 0; i != MAX_COMMENTS; i++)
    {
        if (strlen(thread->comments[i].body) > 0)
        {
            strcpy(response->infos.comments[0].body, message_info->body);
            strcpy(response->infos.comments[0].user_uuid, user_uuid);
            strcpy(response->infos.comments[0].thread_uuid, message_info->thread_uuid);
            strcpy(response->infos.comments[0].team_uuid, message_info->team_uuid);
            j++;
        }
    }
    response->code = 200;
    write(fd, response, sizeof(response_t));
    free(response);
}

static void find_thread(channel_t *channel,
message_manipulation_t *message_info, int fd, char *user_uuid)
{

    for (int i = 0; MAX_THREADS; i++)
    {
        if (strcmp(channel->threads[i].uuid, message_info->thread_uuid) == 0)
        {
            message_info_in_thread(&channel->threads[i],message_info, fd, user_uuid);
            return;
        }
    }
    request_code(fd, 404);
}

static void find_channel(teams_t *team,
message_manipulation_t *message_info, int fd, char *user_uuid)
{
    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strcmp(message_info->channel_uuid, team->channels[i].uuid))
        {
            find_thread(&team->channels[i], message_info, fd, user_uuid);
            return;
        }
    }
    request_code(fd, 404);
}

void get_messages_info(server_t *server, info_t *create, int client)
{
    message_manipulation_t *message_info = &create->messasge;

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(message_info->team_uuid, server->teams[i].uuid))
        {
            if (check_subscribed_request(server->clients[client].socket,
            server->clients[client].uuid, &server->teams[i]) == -1)
                return;
            find_channel(&server->teams[i], message_info,
            server->clients[client].socket, server->clients[client].uuid);
            return;
        }
    }
    request_code(server->clients[client].socket, 404);
}