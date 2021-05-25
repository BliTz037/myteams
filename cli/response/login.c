/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** login
*/

#include "communication.h"
#include "cli.h"

void response_login(cli_t *cli, response_t *rcv)
{
    (void)(cli);
    (void)(rcv);
    printf("MATCH LOGIN\n");
    printf("Code: %d\n", rcv->code);
    printf("User: %s / UUID: %s\n", rcv->user.users->name, rcv->user.users->uuid);
    return;
}