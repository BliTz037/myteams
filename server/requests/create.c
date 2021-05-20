/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** create
*/

#include "server.h"
#include "communication.h"

void create(server_t *server, int client, request_t *request)
{
    create_t *create = &request->create;

    if (create->type == TEAMS)
        addTeam(server, create, client);
}
