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

void list_team(request_t *msg, cli_t *cli)
{
    (void) cli;
    msg->info.type = TEAMS;
}

void list_channel(request_t *msg, cli_t *cli)
{
    strcpy(msg->info.channel.team_uuid, cli->context.team_uuid);
    msg->info.type = CHANNEL;
}

void list_thread(request_t *msg, cli_t *cli)
{
    strcpy(msg->info.thread.team_uuid, cli->context.team_uuid);
    strcpy(msg->info.thread.channel_uuid, cli->context.channel_uuid);
    msg->info.type = THREAD;
}

void list_reply(request_t *msg, cli_t *cli)
{
    strcpy(msg->info.messasge.team_uuid, cli->context.team_uuid);
    strcpy(msg->info.messasge.channel_uuid, cli->context.channel_uuid);
    strcpy(msg->info.messasge.thread_uuid, cli->context.thread_uuid);
    msg->info.type = MESSAGE;
}

int command_list(char **argv, request_t *msg, cli_t *cli)
{
    (void) argv;
    msg->command = LIST;
    switch (get_context(cli))
    {
        case (NOTHING):
            list_team(msg, cli);
            break;
        case (TEAMS):
            list_channel(msg, cli);
            break;
        case (CHANNEL):
            list_thread(msg, cli);
            break;
        case (THREAD):
            list_reply(msg, cli);
            break;
    }
    return (1);
}