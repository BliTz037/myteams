/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** user
*/

#include "communication.h"
#include "cli.h"
#include <stddef.h>

int command_user(char **argv, request_t *msg, cli_t *cli)
{
    (void) cli;
    argv += 0;
    msg->command = USER;
    return (1);
}