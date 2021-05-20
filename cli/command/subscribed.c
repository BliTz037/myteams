/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** subscribed
*/

#include "communication.h"
#include <stdlib.h>
#define SUBSCRIBED_TEAMID_INDEX 0

void command_subscribed(char **argv, request_t *msg)
{
    strcpy(msg->subcribe.team_uuid, argv[SUBSCRIBED_TEAMID_INDEX]);
    msg->command = SUBSCRIBED;
}