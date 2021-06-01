/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** messages
*/

#include "communication.h"
#include "cli.h"
#include <string.h>

int command_messages(char **argv, request_t *msg, cli_t *cli)
{
    (void) cli;
    if (argv[MESSAGE_USERNAME_ID_INDEX] == NULL)
        return (0);
    strcpy(msg->message.user_uuid, argv[MESSAGE_USERNAME_ID_INDEX]);
    msg->command = MESSAGES;
    return (1);
}