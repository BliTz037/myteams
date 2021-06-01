/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** user
*/

#include "communication.h"
#include "../libs/myteams/logging_client.h"
#include "cli.h"

void response_user(response_t *rcv)
{
    client_print_user(rcv->user.users[0].uuid, rcv->user.users[0].name,
    rcv->user.users[1].status);
}

void response_users(response_t *rcv)
{
    for (int i = 0; i != MAX_CLIENTS; i++)
        if (rcv->user.users[i].name[0] != '\0')
            client_print_users(rcv->user.users[i].uuid,
            rcv->user.users[i].name, rcv->user.users[i].status);
}