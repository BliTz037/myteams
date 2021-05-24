/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** logout
*/

#include "communication.h"
#include "cli.h"
#include <stddef.h>
#include <stdio.h>

int command_logout(char **argv, request_t *msg, cli_t *cli)
{
    (void) cli;
    argv += 0;
    msg->command = LOGOUT;
    return (1);
}