/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** create
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"

void create(server_t *server, int client, request_t *request)
{
    create_t *create = &request->create;

    switch (create->type)
    {
        case TEAMS:
            addTeam(server, create, client);
            break;
        case CHANNEL:
            addChannel(server, create, client);
            break;
        case THREAD:
            addThread(server, create, client);
            break;
        case MESSAGE:
            addMessage(server, create, client);
            break;
    }
}
