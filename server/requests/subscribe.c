/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** subscribe
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void subscribe_response(int fd, char *team_uuid, char *user_uuid,
command command)
{
    response_t *response = malloc(sizeof(response_t));

    strcpy(response->subscribe.team_uuid, team_uuid);
    strcpy(response->subscribe.user_uuid, user_uuid);
    response->code = 200;
    response->command = command;
    write(fd, response, sizeof(response_t));
    free(response);
}

static void subscribe_to_team(teams_t *team,
int fd, client_t *client)
{
    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strcmp(team->subscribed_users[i].uuid, client->uuid) == 0)
        {
            request_code(fd, 403);
            return;
        }
    }
    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strlen(team->subscribed_users[i].name) == 0)
        {
            strcpy(team->subscribed_users[i].name, client->name);
            strcpy(team->subscribed_users[i].uuid, client->uuid);
            subscribe_response(fd, team->uuid, client->uuid, SUBSCRIBE);
            server_event_user_subscribed(team->uuid, client->uuid);
            return;
        }
    }
}

void subscribe(server_t *server, int client, request_t *request)
{
    subscribe_t *subscribe = &request->subcribe;

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(subscribe->team_uuid, server->teams[i].uuid) == 0)
        {
            subscribe_to_team(&server->teams[i],
            server->clients[client].socket, &server->clients[client]);
            return;
        }
    }
}

static void unsubscribe_to_team(teams_t *team,
int fd, client_t *client)
{
    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strcmp(team->subscribed_users[i].uuid, client->uuid) == 0)
        {
            memset(team->subscribed_users[i].uuid, 0, UUID_SIZE);
            memset(team->subscribed_users[i].name, 0, MAX_NAME_LENGTH);
            subscribe_response(fd, team->uuid, client->uuid, UNSUBSCRIBE);
            server_event_user_unsubscribed(team->uuid, client->uuid);
            return;
        }
    }
    request_code(fd, 403);
}

void unsubscribe(server_t *server, int client, request_t *request)
{
    subscribe_t *subscribe = &request->subcribe;

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(subscribe->team_uuid, server->teams[i].uuid) == 0)
        {
            unsubscribe_to_team(&server->teams[i],
            server->clients[client].socket, &server->clients[client]);
            return;
        }
    }
}