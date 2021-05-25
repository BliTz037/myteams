/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** info
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"

static void list_info(server_t *server, int client, request_t *request, command command)
{
    info_t *info = &request->info;

    switch (info->type)
    {
        case TEAMS:
            get_teams_infos(server, client, command);
            break;
        case CHANNEL:
            get_channel_info(server, info, client, command);
            break;
        case THREAD:
            get_thread_info(server, info, client, command);
            break;
        case MESSAGE:
            get_messages_info(server, info, client, command);
            break;
    }
}


void list(server_t *server, int client, request_t *request)
{
    list_info(server, client, request, LIST);
}

void info(server_t *server, int client, request_t *request)
{
    list_info(server, client, request, INFO);
}