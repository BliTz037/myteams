/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** create
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"
#include <string.h>

void create(server_t *server, int client, request_t *request)
{
    create_t *create = &request->create;

    switch (create->type)
    {
        case TEAMS:
            add_team(server, create, client);
            break;
        case CHANNEL:
            add_channel(server, create, client);
            break;
        case THREAD:
            add_thread(server, create, client);
            break;
        case MESSAGE:
            add_message(server, create, client);
            break;
        default:
            return;
    }
}

int is_subscribed_to_team(teams_t *team, char *uuid)
{
    for (int i = 0; i != MAX_CLIENTS; i++)
        if (strcmp(team->subscribed_users[i].uuid, uuid) == 0)
            return 1;
    return 0;
}
