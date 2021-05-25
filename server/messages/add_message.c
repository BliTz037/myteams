/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** message
*/

#include "server.h"
#include "communication.h"
#include "logging_server.h"
#include "server_request.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void add_message_response(response_t *response,
message_manipulation_t *message_info, char *user_uuid)
{
    response->code = 200;
    strcpy(response->infos.comments[0].body, message_info->body);
    memcpy(response->infos.comments[0].user_uuid, user_uuid, UUID_SIZE);
    memcpy(response->infos.comments[0].thread_uuid,
    message_info->thread_uuid, UUID_SIZE);
    memcpy(response->infos.comments[0].team_uuid,
    message_info->team_uuid, UUID_SIZE);
}

static void add_message_in_thread(thread_t *thread,
message_manipulation_t *message_info, char *user_uuid, int fd)
{
    response_t *response = malloc(sizeof(response_t));

    for (int i = 0; i != MAX_COMMENTS; i++)
    {
        if (strlen(thread->comments[i].body) == 0)
        {
            strcpy(thread->comments[i].body, message_info->body);
            memcpy(thread->comments[i].user_uuid, user_uuid, UUID_SIZE);
            server_event_reply_created(message_info->thread_uuid,
            user_uuid, message_info->body);
            add_message_response(response, message_info, user_uuid);
            write(fd, response, sizeof(response_t));
            free(response);
            return;
        }
    }
}

static void find_thread(channel_t *channel,
message_manipulation_t *message_info, char *user_uuid, int fd)
{

    for (int i = 0; MAX_THREADS; i++)
    {
        if (strcmp(channel->threads[i].uuid, message_info->thread_uuid) == 0)
        {
            add_message_in_thread(&channel->threads[i], message_info, user_uuid, fd);
            return;
        }
    }
    request_404_error(fd, message_info->thread_uuid, THREAD);

}

static void find_channel(teams_t *team,
message_manipulation_t *message_info, char *user_uuid, int fd)
{
    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strcmp(message_info->channel_uuid, team->channels[i].uuid))
        {
            find_thread(&team->channels[i], message_info, user_uuid, fd);
            return;
        }
    }
    request_404_error(fd, message_info->channel_uuid, CHANNEL);
}

void add_message(server_t *server, create_t *create, int client)
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
            server->clients[client].uuid, server->clients[client].socket);
            return;
        }
    }
    request_404_error(server->clients[client].socket,
    message_info->team_uuid, TEAMS);
}