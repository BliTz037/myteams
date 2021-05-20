/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** request
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"

void handle_request(server_t *server, int client, request_t *request)
{
    for (int i = 0; i != sizeof(request_list) / sizeof(*request_list); i++)
    {
        if (request->command == request_list[i].command)
        {
            request_list[i].fct(server, client, request);
            return;
        }
    }
}