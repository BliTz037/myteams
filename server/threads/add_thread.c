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
#include <time.h>

static void notify_all_users(server_t *server, teams_t *team, thread_t *thread)
{
    response_t *response = malloc(sizeof(response_t));

    response->code = 200;
    response->command = CREATE;
    response->create.is_global_ping = 1;
    strcpy(response->create.thread[0].thread_message, thread->message);
    strcpy(response->create.thread[0].thread_title, thread->title);
    response->create.thread[0].timestamp = thread->timestamp;
    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (is_subscribed_to_team(team, server->clients[i].uuid) == 1
        && server->clients[i].loged == 1)
        {
            write(server->clients[i].socket, response, sizeof(response_t));
        }
    }
    free(response);
}

static void add_thread_response(response_t *response,
thread_t *thread)
{
    response->code = 200;
    response->command = CREATE;
    response->create.is_global_ping = 0;
    strcpy(response->create.thread[0].thread_message, thread->message);
    strcpy(response->create.thread[0].thread_title, thread->title);
    response->create.thread[0].timestamp = thread->timestamp;
}

static thread_t * add_thread_in_channel(server_t *server,
int client, channel_t *channel, thread_manipulation_t *thread_info)
{
    char *uuid = generate_uuid();
    response_t *response = malloc(sizeof(response_t));

    for (int i = 0; MAX_THREADS; i++) {
        if (strlen(channel->threads[i].title) == 0) {
            strcpy(channel->threads[i].title, thread_info->thread_title);
            strcpy(channel->threads[i].message, thread_info->thread_message);
            memcpy(channel->threads[i].uuid, uuid, UUID_SIZE);
            memcpy(channel->threads[i].user_uuid, 
            server->clients[client].uuid, UUID_SIZE);
            channel->threads[i].timestamp = time(NULL);
            server_event_thread_created(thread_info->channel_uuid,
            uuid, server->clients[client].uuid, thread_info->thread_title,
            thread_info->thread_message);
            add_thread_response(response, &channel->threads[i]);
            write(server->clients[client].socket, response, sizeof(response_t));
            free (uuid);
            free(response);
            return &channel->threads[i];
        }
    }
}

static void find_channel(server_t *server, int client, teams_t *team,
thread_manipulation_t *thread_info)
{
    thread_t *thread ;

    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strcmp(thread_info->channel_uuid, team->channels[i].uuid))
        {
            thread = add_thread_in_channel(server, client,
            &team->channels[i], thread_info);
            notify_all_users(server, team, thread);
            return;
        }
    }
    request_404_error(server->clients[client].socket,
    thread_info->channel_uuid, CHANNEL);
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
            find_channel(server, client, &server->teams[i], thread_info);
            return;
        }
    }
    request_404_error(server->clients[client].socket,
    thread_info->team_uuid, TEAMS);
}