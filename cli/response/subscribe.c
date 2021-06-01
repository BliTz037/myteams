/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** subscribe
*/

#include "communication.h"
#include "../libs/myteams/logging_client.h"
#include "cli.h"

void response_subscribe(response_t *rcv)
{
    client_print_subscribed(rcv->subscribe.user_uuid,
    rcv->subscribe.team_uuid);
}