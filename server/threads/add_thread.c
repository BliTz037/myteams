/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** thread
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include "logging_server.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static void add_thread_response(response_t *response,
thread_t *thread)
{
    response->code = 200;
    strcpy(response->infos.thread[0].thread_message, thread->message);
    strcpy(response->infos.thread[0].thread_title, thread->title);
}

static void add_thread_in_channel(channel_t *channel,
thread_manipulation_t *thread_info, char *user_uuid, int fd)
{
    char *uuid = generate_uuid();
    response_t *response = malloc(sizeof(response_t));

    for (int i = 0; MAX_THREADS; i++)
    {
        if (strlen(channel->threads[i].title) == 0)
        {
            strcpy(channel->threads[i].title, thread_info->thread_title);
            strcpy(channel->threads[i].message, thread_info->thread_message);
            memcpy(channel->threads[i].uuid, uuid, UUID_SIZE);
            memcpy(channel->threads[i].user_uuid, user_uuid, UUID_SIZE);
            server_event_thread_created(thread_info->channel_uuid,
            uuid, user_uuid, thread_info->thread_title, thread_info->thread_message);
            add_thread_response(response, &channel->threads[i]);
            write(fd, response, sizeof(response_t));
            free (uuid);
            free(response);
        }
    }
}

static void find_channel(teams_t *team,
thread_manipulation_t *thread_info, char *user_uuid, int fd)
{
    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strcmp(thread_info->channel_uuid, team->channels[i].uuid))
        {
            add_thread_in_channel(&team->channels[i], thread_info, user_uuid, fd);
            return;
        }
    }
    request_404_error(fd, thread_info->channel_uuid, CHANNEL);
}

void add_thread(server_t *server, create_t *create, int client)
{
    thread_manipulation_t *thread_info = &create->thread;

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(thread_info->team_uuid, server->teams[i].uuid))
        {
            if (check_subscribed_request(server->clients[client].socket,
            server->clients[client].uuid, &server->teams[i]) == -1)
                return;
            find_channel(&server->teams[i], thread_info,
            server->clients[client].uuid, server->clients[client].socket);
            return;
        }
    }
    request_404_error(server->clients[client].socket,
    thread_info->team_uuid, TEAMS);
}