/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** add_teams
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include <string.h>
#include "logging_server.h"
#include <uuid/uuid.h>
#include <stdlib.h>
#include <unistd.h>

static void notify_all_users(server_t *server, teams_t *team)
{
    response_t *response = malloc(sizeof(response_t));
    response->code = 200;
    response->command = CREATE;
    response->create.type = TEAMS;
    response->create.is_global_ping = 1;
    strcpy(response->create.teams[0].team_name, team->name);
    memcpy(response->create.teams[0].team_uuid, team->uuid, UUID_SIZE);
    strcpy(response->create.teams[0].team_description, team->description);
    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (server->clients[i].loged == 1)
            write(server->clients[i].socket, response, sizeof(response_t));
    }
    free(response);
}

static void add_creator_to_subscribed(teams_t *teams, client_t *client)
{
    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strlen(teams->subscribed_users[i].uuid) == 0)
        {
            memcpy(teams->subscribed_users[i].uuid, client->uuid, UUID_SIZE);
            strcpy(teams->subscribed_users[i].name, client->name);
            return;
        }
    }
}

static void add_team_response(int fd, teams_t *team)
{
    response_t *response = malloc(sizeof(response_t));
    response->code = 200;
    response->command = CREATE;
    response->create.type = TEAMS;
    response->create.is_global_ping = 0;
    strcpy(response->create.teams[0].team_name, team->name);
    memcpy(response->create.teams[0].team_uuid, team->uuid, UUID_SIZE);
    strcpy(response->create.teams[0].team_description, team->description);
    write(fd, response, sizeof(response_t));
    free(response);
}

int check_team_exist(server_t *server, create_t *create, int client)
{
    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(server->teams[i].name, create->teams.team_name) == 0)
        {
            request_code(server->clients[client].socket, 403);
            return -1;
        }
    }
    return 0;
}

void add_team(server_t *server, create_t *create, int client)
{
    char *uuid;

    if (check_team_exist(server, create, client) == -1)
        return;
    for (int i = 0; i != MAX_TEAMS; i++) {
        if (strlen(server->teams[i].name) == 0) {
            uuid = generate_uuid();
            strcpy(server->teams[i].name, create->teams.team_name);
            strcpy(server->teams[i].description,
            create->teams.team_description);
            memcpy(server->teams[i].uuid, uuid, UUID_SIZE);
            server_event_team_created(uuid, create->teams.team_name,
            server->clients[client].name);
            add_team_response(server->clients[client].socket,
            &server->teams[i]);
            add_creator_to_subscribed(&server->teams[i], &server->clients[i]);
            notify_all_users(server, &server->teams[i]);
            free(uuid);
            return;
        }
    }
}