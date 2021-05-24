/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** subscribe
*/

#include "communication.h"
#include "cli.h"
#include <string.h>
#define SUBSCRIBE_TEAMID_INDEX 0

int command_subscribe(char **argv, request_t *msg, cli_t *cli)
{
    (void) cli;
    if (argv[SUBSCRIBE_TEAMID_INDEX] == NULL)
        return (0);
    strcpy(msg->subcribe.team_uuid, argv[SUBSCRIBE_TEAMID_INDEX]);
    msg->command = SUBSCRIBE;
    return (1);
}