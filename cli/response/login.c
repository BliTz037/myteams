/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** login
*/

#include "communication.h"
#include "../libs/myteams/logging_client.h"
#include "cli.h"

void response_login(response_t *rcv)
{
    if (rcv->code == 200 || rcv->code == 201) {
        if (rcv->code == 201)
            printf("Welcome %s, you are register.\n", rcv->user.users->name);
        client_event_logged_in(rcv->user.users->uuid, rcv->user.users->name);
    }
    return;
}