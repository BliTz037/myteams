/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** teams
*/ 

#include "server.h"
#include "communication.h"
#include <string.h>
#include "logging_server.h"
#include <uuid/uuid.h>
#include <stdlib.h>
#include <unistd.h>

static void add_team_response(response_t *response, teams_t *team)
{
    response->code = 200;
    response->infos.teams[0] = *team;
}

void add_team(server_t *server, create_t *create, int client)
{   
    char *uuid = generate_uuid();
    int fd = server->clients[client].socket;
    response_t *response = malloc(sizeof(response_t));

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strlen(server->teams[i].name) == 0)
        {
            strcpy(server->teams[i].name, create->teams.team_name);
            strcpy(server->teams[i].description, create->teams.team_description);
            strcpy(server->teams[i].uuid, uuid);
            server_event_team_created(uuid, create->teams.team_name, create->teams.team_description);
            add_team_response(response, &server->teams[i]);
            write(fd, response, sizeof(response_t));
            free(uuid);
            free(response);
            return;
        }
    }
}