/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** user
*/

#include "communication.h"
#include <stddef.h>

void command_user(char **argv, request_t *msg)
{
    argv += 0;
    msg->command = USER;
}