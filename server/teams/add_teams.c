/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** teams
*/ 

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include <string.h>
#include "logging_server.h"
#include <uuid/uuid.h>
#include <stdlib.h>
#include <unistd.h>

static void add_team_response(int fd, teams_t *team)
{
    response_t *response = malloc(sizeof(response_t));
    response->code = 200;
    strcpy(response->infos.teams[0].team_name, team->name);
    memcpy(response->infos.teams[0].team_uuid, team->uuid, UUID_SIZE);
    strcpy(response->infos.teams[0].team_description, team->description);
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
            strcpy(server->teams[i].description, create->teams.team_description);
            memcpy(server->teams[i].uuid, uuid, UUID_SIZE);
            server_event_team_created(uuid, create->teams.team_name, create->teams.team_description);
            add_team_response(server->clients[client].socket, &server->teams[i]);
            free(uuid);
            return;
        }
    }
}