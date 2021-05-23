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

static void thread_info_in_channel(channel_t *channel, int fd)
{
    response_t *response = malloc(sizeof(response_t));
    int j = 0;

    for (int i = 0; MAX_THREADS; i++)
    {
        if (strlen(channel->threads[i].title) > 0)
        {
            response->infos.thread[j] = channel->threads[i];
            j++;
        }
    }
    response->code = 200;
    write(fd, response, sizeof(response_t));
    free(response);
}

static void find_channel(teams_t *team,
thread_manipulation_t *thread_info, int fd)
{
    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strcmp(thread_info->channel_uuid, team->channels[i].uuid))
        {
            thread_info_in_channel(&team->channels[i], fd);
            return;
        }
    }
    request_code(fd, 404);
}

void get_thread_info(server_t *server, info_t *info, int client)
{
    thread_manipulation_t *thread_info = &info->thread;

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(thread_info->team_uuid, server->teams[i].uuid))
        {
            find_channel(&server->teams[i], thread_info,
            server->clients[client].socket);
            return;
        }
    }
    request_code(server->clients[client].socket, 404);
}