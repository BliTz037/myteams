/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** unsubscribe
*/

#include "communication.h"
#include "../libs/myteams/logging_client.h"
#include "cli.h"

void response_unsubscribed(response_t *rcv)
{
    client_print_unsubscribed(rcv->subscribe.user_uuid,
    rcv->subscribe.team_uuid);
    return;
}