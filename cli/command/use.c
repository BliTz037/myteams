/*
** EPITECH PROJECT, 1010
** B-NWP-400-PAR-4-0-myteams-tom.rives [SSH: valoon.fr]
** File description:
** use
*/

#include "communication.h"
#include "cli.h"

int command_use(char **argv, request_t *msg, cli_t *cli)
{
    (void) msg;
    if (argv[0] != NULL && argv[1] == NULL) {
        memcpy(cli->context.team_uuid, argv[0], UUID_SIZE);
        printf("%s / %s\n", cli->context.team_uuid, argv[0]);
        strcpy(cli->context.channel_uuid, "0");
        strcpy(cli->context.thread_uuid, "0");
    } else if (argv[0] != NULL && argv[1] != NULL && argv[2] == NULL) {
        strcpy(cli->context.team_uuid, argv[0]);
        strcpy(cli->context.channel_uuid, argv[1]);
        strcpy(cli->context.thread_uuid, "0");
    } else if (argv[0] != NULL && argv[1] != NULL && argv[2] != NULL) {
        strcpy(cli->context.team_uuid, argv[0]);
        strcpy(cli->context.channel_uuid, argv[1]);
        strcpy(cli->context.thread_uuid, argv[2]);
    }
    return (0);
}