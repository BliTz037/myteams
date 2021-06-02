/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** logout
*/

#include "communication.h"
#include "../libs/myteams/logging_client.h"
#include "cli.h"

void response_logout(response_t *rcv)
{
    client_event_logged_out(rcv->user.users->uuid, rcv->user.users->name);
}