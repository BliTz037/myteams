/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** unsubscribed
*/

#include "communication.h"
#include <stdlib.h>
#define UNSUBSCRIBED_TEAMID_INDEX 0

void command_unsubscribed(char **argv, request_t *msg)
{
    msg->subcribe.team_uuid = atoi(argv[UNSUBSCRIBED_TEAMID_INDEX]);
    msg->command = UNSUBSCRIBE;
}