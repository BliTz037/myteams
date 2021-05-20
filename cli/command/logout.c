/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** logout
*/

#include "communication.h"
#include <stddef.h>
#include <stdio.h>

void command_logout(char **argv, request_t *msg)
{
    argv += 0;
    msg->command = LOGOUT;
}