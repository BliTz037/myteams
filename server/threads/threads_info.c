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
            strcpy(response->infos.thread[j].thread_message, channel->threads[i].message);
            strcpy(response->infos.thread[j].thread_title, channel->threads[i].title);
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
            if (check_subscribed_request(server->clients[client].socket,
            server->clients[client].uuid, &server->teams[i]) == -1)
                return;
            find_channel(&server->teams[i], thread_info,
            server->clients[client].socket);
            return;
        }
    }
    request_code(server->clients[client].socket, 404);
}