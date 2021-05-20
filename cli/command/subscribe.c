/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** subscribe
*/

#include "communication.h"
#include <stdlib.h>
#define SUBSCRIBE_TEAMID_INDEX 0

void command_subscribe(char **argv, request_t *msg)
{
    msg->subcribe.team_uuid = atoi(argv[SUBSCRIBE_TEAMID_INDEX]);
    msg->command = SUBSCRIBE;
}