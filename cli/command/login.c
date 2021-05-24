/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** login
*/

#include "communication.h"
#include "cli.h"
#include <string.h>
#define LOGIN_USERNAME_INDEX 0

int command_login(char **argv, request_t *msg, cli_t *cli)
{
    (void) cli;
    if (argv[LOGIN_USERNAME_INDEX] == NULL)
        return (0);
    strcpy(msg->login.username, argv[LOGIN_USERNAME_INDEX]);
    msg->command = LOGIN;
    return (1);
}