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

void subscribed(server_t *server, int client, request_t *request)
{
    subscribe_t *subscribed = &request->subcribe;

    if (strlen(subscribed->team_uuid) == 0)
        list_teams_subscribed(server, client);
    else
        list_user_in_team(server, client, subscribed->team_uuid);
}