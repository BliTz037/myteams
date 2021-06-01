/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** info
*/

#include "communication.h"
#include "cli.h"
#include <stddef.h>
#include <stdio.h>

void info_user(request_t *msg, cli_t *cli)
{
    (void) cli;
    msg->info.type = USER_INFO;
}

void info_teams(request_t *msg, cli_t *cli)
{
    strcpy(msg->info.channel.team_uuid, cli->context.team_uuid);
    msg->info.type = TEAMS;
}

void info_channel(request_t *msg, cli_t *cli)
{
    strcpy(msg->info.thread.team_uuid, cli->context.team_uuid);
    strcpy(msg->info.thread.channel_uuid, cli->context.channel_uuid);
    msg->info.type = CHANNEL;
}

void info_thread(request_t *msg, cli_t *cli)
{
    strcpy(msg->info.messasge.team_uuid, cli->context.team_uuid);
    strcpy(msg->info.messasge.channel_uuid, cli->context.channel_uuid);
    strcpy(msg->info.messasge.thread_uuid, cli->context.thread_uuid);
    msg->info.type = THREAD;
}

int command_info(char **argv, request_t *msg, cli_t *cli)
{
    (void) argv;
    msg->command = INFO;
    printf("get_context : %d\n", get_context(cli));
    switch (get_context(cli))
    {
        case (NOTHING):
            info_user(msg, cli);
            break;
        case (TEAMS):
            info_teams(msg, cli);
            break;
        case (CHANNEL):
            info_channel(msg, cli);
            break;
        case (THREAD):
            info_thread(msg, cli);
            break;
    }
    return (1);
}
