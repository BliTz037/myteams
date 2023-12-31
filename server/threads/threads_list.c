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

static void fill_thread_response(response_t *response, thread_t *thread, int j)
{
    strcpy(response->infos.thread[j].thread_message, thread->message);
    strcpy(response->infos.thread[j].thread_title, thread->title);
    response->infos.thread[j].timestamp = thread->timestamp;
    memcpy(response->infos.thread[j].user_uuid, thread->user_uuid, UUID_SIZE);
    memcpy(response->infos.thread[j].thread_uuid, thread->uuid, UUID_SIZE);
}

static void thread_info_in_channel(channel_t *channel, int fd)
{
    response_t *response = malloc(sizeof(response_t));
    int j = 0;

    response->infos.nb = 0;
    for (int i = 0; i != MAX_THREADS; i++)
    {
        if (strlen(channel->threads[i].title) > 0)
        {
            fill_thread_response(response, &channel->threads[i], j);
            j++;
            response->infos.nb++;
        }
    }
    response->code = 200;
    response->command = LIST;
    response->infos.type = THREAD;
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
    request_404_error(fd, thread_info->channel_uuid, CHANNEL);
}

void get_thread_list(server_t *server, info_t *info,
int client)
{
    thread_manipulation_t *thread_info = &info->thread;

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(thread_info->team_uuid, server->teams[i].uuid) == 0)
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