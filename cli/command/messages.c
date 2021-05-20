/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** messages
*/

#include "communication.h"
#include <stdlib.h>
#define MESSAGE_USERNAME_ID_INDEX 0

void command_messages(char **argv, request_t *msg)
{
    msg->message.user_uuid = atoi(argv[MESSAGE_USERNAME_ID_INDEX]);
    msg->command = MESSAGES;
}