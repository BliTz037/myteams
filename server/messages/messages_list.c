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
message_manipulation_t *message_info, int fd, response_t *response)
{
    int j = 0;
    for (int i = 0; i != MAX_COMMENTS; i++)
    {
        if (strlen(thread->comments[i].body) > 0)
        {
            strcpy(response->infos.comments[0].body, message_info->body);
            memcpy(response->infos.comments[0].thread_uuid,
            message_info->thread_uuid, UUID_SIZE);
            memcpy(response->infos.comments[0].team_uuid,
            message_info->team_uuid, UUID_SIZE);
            response->infos.comments[0].timestamp =
            thread->comments[i].timestamp;
            j++;
        }
    }
    response->code = 200;
    response->infos.type = MESSAGE;
    write(fd, response, sizeof(response_t));
    free(response);
}

static void find_thread(channel_t *channel,
message_manipulation_t *message_info, int fd, response_t *response)
{

    for (int i = 0; i != MAX_THREADS; i++)
    {
        if (strcmp(channel->threads[i].uuid, message_info->thread_uuid) == 0)
        {
            message_info_in_thread(&channel->threads[i], message_info, fd,
            response);
            return;
        }
    }
    request_404_error(fd, message_info->thread_uuid, THREAD);
}

static void find_channel(teams_t *team,
message_manipulation_t *message_info, int fd, response_t *response)
{
    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strcmp(message_info->channel_uuid, team->channels[i].uuid))
        {
            find_thread(&team->channels[i], message_info, fd, response);
            return;
        }
    }
    request_404_error(fd, message_info->channel_uuid, CHANNEL);
}

void get_messages_list(server_t *server, info_t *create,
int client)
{
    message_manipulation_t *message_info = &create->messasge;
    response_t *response;

    for (int i = 0; i != MAX_TEAMS; i++) {
        if (strcmp(message_info->team_uuid, server->teams[i].uuid)) {
            if (check_subscribed_request(server->clients[client].socket,
            server->clients[client].uuid, &server->teams[i]) == -1)
                return;
            response = malloc(sizeof(response_t));
            response->command = LIST;
            memcpy(response->infos.comments[0].user_uuid,
            server->clients[client].uuid, UUID_SIZE);
            find_channel(&server->teams[i], message_info,
            server->clients[client].socket, response);
            free(response);
            return;
        }
    }
    request_404_error(server->clients[client].socket,
    message_info->team_uuid, TEAMS);
}