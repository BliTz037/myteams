/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** info
*/

#include "server.h"
#include "communication.h"
#include "server_request.h"

void list_info(server_t *server, int client, request_t *request)
{
    info_t *info = &request->info;

    switch (info->type)
    {
        case TEAMS:
            get_teams_infos(server, client);
            break;
        case CHANNEL:
            get_channel_info(server, info, client);
            break;
        case THREAD:
            get_thread_info(server, info, client);
            break;
        case MESSAGE:
            get_messages_info(server, info, client);
            break;
    }
}