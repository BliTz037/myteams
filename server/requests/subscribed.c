/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** subscribed
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void add_team_response(response_t *response, teams_t *team,
int *response_idx)
{
    strcpy(response->subscribed.teams[*response_idx].team_description, team->description);
    strcpy(response->subscribed.teams[*response_idx].team_name, team->name);
    strcpy(response->subscribed.teams[*response_idx].team_uuid, team->uuid);
    (*response_idx)++;
}

static void list_teams_subscribed(server_t *server, int client)
{
    response_t *response = malloc(sizeof(response));
    int k = 0;

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        for (int j = 0; j != MAX_CLIENTS; j++)
        {
            if (strcmp(server->clients[client].uuid,
            server->teams[i].subscribed_users[j].uuid) == 0)
                add_team_response(response, &server->teams[i], &k);
        }
    }
    response->code = 200;
    response->command = SUBSCRIBED;
    write(server->clients[client].socket, response, sizeof(response_t));
    free(response);
}

static void user_in_team_response(teams_t *team, int fd)
{
    response_t *response = malloc(sizeof(response_t));
    int j = 0;

    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strlen(team->subscribed_users[i].uuid) > 0)
        {
            strcpy(response->subscribed.users[j].name, team->subscribed_users[i].name);
            strcpy(response->subscribed.users[j].uuid, team->subscribed_users[i].uuid);
            j++;
        }
    }
    response->code = 200;
    response->command = SUBSCRIBED;
    write(fd, response, sizeof(response_t));
    free(response);
}

static void list_user_in_team(server_t *server, int client, char *team_uuid)
{
    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(server->teams[i].uuid, team_uuid) == 0)
        {
            user_in_team_response(&server->teams[i], server->clients[client].socket);
            return;
        }
    }
    request_code(server->clients[client].socket, 403);
}

void subscribed(server_t *server, int client, request_t *request)
{
    subscribe_t *subscribed = &request->subcribe;

    if (strlen(subscribed->team_uuid) == 0)
        list_teams_subscribed(server, client);
    else
        list_user_in_team(server, client, subscribed->team_uuid);
}