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

void add_team(server_t *server, create_t *create, int client)
{   
    char *uuid = generate_uuid();

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strlen(server->teams[i].name) == 0)
        {
            strcpy(server->teams[i].name, create->teams.team_name);
            strcpy(server->teams[i].description, create->teams.team_description);
            strcpy(server->teams[i].uuid, uuid);
            server_event_team_created(uuid, create->teams.team_name, create->teams.team_description);
            free(uuid);
            return;
        }
    }
}