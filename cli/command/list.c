/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** list
*/

#include "communication.h"
#include "cli.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

int command_list(char **argv, request_t *msg, cli_t *cli)
{
    argv += 0;
    msg += 0;
    (void) cli;
    msg = NULL;
    printf("No parser for 'list' for now\n");
    return (1);
}