/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** send
*/

#include "communication.h"
#include "cli.h"
#include <string.h>
#include <stdlib.h>
#define SEND_USERNAME_INDEX 0
#define SEND_BODY_INDEX 1

int command_send(char **argv, request_t *msg, cli_t *cli)
{
    (void) cli;
    if (argv[SEND_USERNAME_INDEX] == NULL || argv[SEND_BODY_INDEX] == NULL)
        return (0);
    strcpy(msg->send.user_uuid, argv[SEND_USERNAME_INDEX]);
    strcpy(msg->send.body, argv[SEND_BODY_INDEX]);
    msg->command = SEND;
    return (1);
}