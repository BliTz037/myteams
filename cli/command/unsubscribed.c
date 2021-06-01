/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** unsubscribed
*/

#include "communication.h"
#include "cli.h"
#include <string.h>

int command_unsubscribed(char **argv, request_t *msg, cli_t *cli)
{
    (void) cli;
    if (argv[UNSUBSCRIBED_TEAMID_INDEX] == NULL)
        return (0);
    strcpy(msg->subcribe.team_uuid, argv[UNSUBSCRIBED_TEAMID_INDEX]);
    msg->command = UNSUBSCRIBE;
    return (1);
}