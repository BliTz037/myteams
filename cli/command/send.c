/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** send
*/

#include "communication.h"
#include <string.h>
#include <stdlib.h>
#define SEND_USERNAME_INDEX 0
#define SEND_BODY_INDEX 1

void command_send(char **argv, request_t *msg)
{
    strcpy(msg->send.user_uuid, argv[SEND_USERNAME_INDEX]);
    strcpy(msg->send.body, argv[SEND_BODY_INDEX]);
    msg->command = SEND;
}