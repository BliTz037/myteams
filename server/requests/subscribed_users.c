/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** subscribed_users
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static int get_user_status_by_uuid(server_t *server, char *uuid)
{
    for (int i = 0; i != MAX_CLIENTS; i++)
    {
        if (strcmp(uuid, server->clients[i].uuid) == 0)
            return server->clients[i].loged == 1 ? 0 : 1;
    }
    return -1;
}

static void user_in_team_response(server_t *server, teams_t *team, int fd)
{
    response_t *response = malloc(sizeof(response_t));
    int j = 0;

    for (int i = 0; i != MAX_CLIENTS; i++) {
        if (strlen(team->subscribed_users[i].uuid) > 0) {
            strcpy(response->subscribed.users[j].name,
            team->subscribed_users[i].name);
            strcpy(response->subscribed.users[j].uuid,
            team->subscribed_users[i].uuid);
            response->subscribed.users[j].status =
            get_user_status_by_uuid(server,
            response->subscribed.users[j].uuid);
            j++;
        }
    }
    response->code = 200;
    response->command = SUBSCRIBED;
    write(fd, response, sizeof(response_t));
    free(response);
}

void list_user_in_team(server_t *server, int client, char *team_uuid)
{
    for (int i = 0; i != MAX_TEAMS; i++)
    {
        if (strcmp(server->teams[i].uuid, team_uuid) == 0)
        {
            user_in_team_response(server, &server->teams[i], server->clients[client].socket);
            return;
        }
    }
    request_code(server->clients[client].socket, 403);
}