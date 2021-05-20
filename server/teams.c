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

static void addTeam(server_t *server, char const *name, char const *description,
char const *user_uuid)
{
    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strlen(server->teams[i].name) == 0)
        {
            strcpy(server->teams[i].name, name);
            strcpy(server->teams[i].description, description);
            //server_event_team_created(server->teams[i].uuid, name, user_uuid);
            return;
        }
    }
}

void handle_team(server_t *server, int client, request_t *request)
{

}