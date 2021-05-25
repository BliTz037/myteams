/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** teams_info
*/

#include "server.h"
#include "communication.h"
#include <string.h>
#include "logging_server.h"
#include "server_request.h"
#include <uuid/uuid.h>
#include <stdlib.h>
#include <unistd.h>

void get_teams_infos(server_t *server, int client, command command)
{
    response_t *response = malloc(sizeof(response_t));
    int j = 0;

    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strlen(server->teams[i].name) > 0)
        {
            strcpy(response->infos.teams[j].team_name, server->teams[i].name);
            strcpy(response->infos.teams[j].team_uuid, server->teams[i].uuid);
            strcpy(response->infos.teams[j].team_description, server->teams[i].description);
            j++;
        }
    }
    response->code = 200;
    response->command = command;
    write(server->clients[client].socket, response, sizeof(response_t));
    free(response);
}