/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** login
*/

#include "communication.h"
#include <string.h>
#define LOGIN_USERNAME_INDEX 0

void command_login(char **argv, request_t *msg)
{
    strcpy(msg->login.username, argv[LOGIN_USERNAME_INDEX]);
    msg->command = LOGIN;
}