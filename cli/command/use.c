/*
** EPITECH PROJECT, 1010
** B-NWP-400-PAR-4-0-myteams-tom.rives [SSH: valoon.fr]
** File description:
** use
*/

#include "communication.h"
#include "cli.h"

void use_nothing(cli_t *cli)
{
    strcpy(cli->context.team_uuid, "\0");
    strcpy(cli->context.channel_uuid, "\0");
    strcpy(cli->context.thread_uuid, "\0");
}

void use_team(char **argv, cli_t *cli)
{
    strcpy(cli->context.team_uuid, argv[0]);
    printf("%s / %s\n", cli->context.team_uuid, argv[0]);
    strcpy(cli->context.channel_uuid, "\0");
    strcpy(cli->context.thread_uuid, "\0");
}

void use_channel(char **argv, cli_t *cli)
{
    strcpy(cli->context.team_uuid, argv[0]);
    strcpy(cli->context.channel_uuid, argv[1]);
    strcpy(cli->context.thread_uuid, "\0");
}

void use_thread(char **argv, cli_t *cli)
{
    strcpy(cli->context.team_uuid, argv[0]);
    strcpy(cli->context.channel_uuid, argv[1]);
    strcpy(cli->context.thread_uuid, argv[2]);
}

int command_use(char **argv, request_t *msg, cli_t *cli)
{
    (void) msg;
    if (argv[0] == NULL) {
        use_nothing(cli);
        return (0);
    }
    if (argv[0] != NULL && argv[1] == NULL) {
        use_team(argv, cli);
        return (0);
    } 
    if (argv[0] != NULL && argv[1] != NULL && argv[2] == NULL) {
        use_channel(argv, cli);
        return (0);
    } 
    if (argv[0] != NULL && argv[1] != NULL && argv[2] != NULL) {
        use_thread(argv, cli);
        return (0);
    }
    return (0);
}