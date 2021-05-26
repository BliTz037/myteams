/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** threads_info
*/

#include "server.h"
#include "communication.h"
#include "logging_server.h"
#include "server_request.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static void thread_info_in_channel(channel_t *channel, int fd,
message_manipulation_t *thread_info)
{
    response_t *response;

    for (int i = 0; MAX_THREADS; i++)
    {
        if (strcmp(channel->threads[i].uuid, thread_info->thread_uuid) != 0)
        {
            response = malloc(sizeof(response_t));
            strcpy(response->infos.thread[0].thread_message,
            channel->threads[i].message);
            strcpy(response->infos.thread[0].thread_title,
            channel->threads[i].title);
            response->infos.thread[0].timestamp = 
            channel->threads[i].timestamp;
            response->code = 200;
            response->command = LIST;
            write(fd, response, sizeof(response_t));
            free(response);
        }
    }
    request_404_error(fd, thread_info->thread_uuid, THREAD);
}

static void find_channel(teams_t *team,
message_manipulation_t *thread_info, int fd)
{
    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strcmp(thread_info->channel_uuid, team->channels[i].uuid))
        {
            thread_info_in_channel(&team->channels[i], fd, thread_info);
            return;
        }
    }
    request_404_error(fd, thread_info->channel_uuid, CHANNEL);
}

void get_thread_info(server_t *server, info_t *info,
int client)
{
    message_manipulation_t *thread_info = &info->messasge;

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(thread_info->team_uuid, server->teams[i].uuid))
        {
            if (check_subscribed_request(server->clients[client].socket,
            server->clients[client].uuid, &server->teams[i]) == -1)
                return;
            find_channel(&server->teams[i], thread_info,
            server->clients[client].socket);
            return;
        }
    }
    request_404_error(server->clients[client].socket, thread_info->team_uuid,
    TEAMS);
}