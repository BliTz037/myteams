/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** subscribed
*/

#include "communication.h"
#include "cli.h"
#include <string.h>

int command_subscribed(char **argv, request_t *msg, cli_t *cli)
{
    (void) cli;
    if (argv[SUBSCRIBED_TEAMID_INDEX] == NULL)
        return (0);
    strcpy(msg->subcribe.team_uuid, argv[SUBSCRIBED_TEAMID_INDEX]);
    msg->command = SUBSCRIBED;
    return (1);
}