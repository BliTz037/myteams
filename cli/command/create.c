/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives [SSH: valoon.fr]
** File description:
** create
*/

#include <stddef.h>
#include <stdio.h>
#include "communication.h"
#include "cli.h"

void create_new_team(char **argv, request_t *msg, cli_t *cli)
{
    strcpy(msg->create.teams.team_name, argv[0]);
    strcpy(msg->create.teams.team_description, argv[1]);
    msg->create.type = TEAMS;
}

void create_new_channel(char **argv, request_t *msg, cli_t *cli)
{
    strcpy(msg->create.channel.channel_name, argv[0]);
    strcpy(msg->create.channel.channel_description, argv[1]);
    strcpy(msg->create.channel.team_uuid, cli->context.team_uuid);
    msg->create.type = CHANNEL;
}

void create_new_thread(char **argv, request_t *msg, cli_t *cli)
{
    strcpy(msg->create.thread.thread_title, argv[0]);
    strcpy(msg->create.thread.thread_message, argv[1]);
    strcpy(msg->create.thread.team_uuid, cli->context.team_uuid);
    strcpy(msg->create.thread.channel_uuid, cli->context.channel_uuid);
    msg->create.type = THREAD;
}

void create_new_reply(char **argv, request_t *msg, cli_t *cli)
{
    strcpy(msg->create.thread.thread_title, argv[0]);
    strcpy(msg->create.messasge.team_uuid, cli->context.team_uuid);
    strcpy(msg->create.messasge.channel_uuid, cli->context.channel_uuid);
    strcpy(msg->create.messasge.thread_uuid, cli->context.thread_uuid);
    msg->create.type = MESSAGE;
}

int command_create(char **argv, request_t *msg, cli_t *cli)
{
    if (strcmp(cli->context.team_uuid, "0") == 0 &&
    argv[0] != NULL && argv[1] != NULL)
        create_new_team(argv, msg, cli);
    else if (strcmp(cli->context.channel_uuid, "0") == 0 &&
    strcmp(cli->context.thread_uuid, "0") == 0 &&
    argv[0] != NULL && argv[1] != NULL)
        create_new_channel(argv, msg, cli);
    else if (strcmp(cli->context.thread_uuid, "0") == 0 &&
    argv[0] != NULL && argv[1] != NULL)
        create_new_thread(argv, msg, cli);
    else if (strcmp(cli->context.team_uuid, "0") != 0 &&
    strcmp(cli->context.channel_uuid, "0") != 0 &&
    strcmp(cli->context.thread_uuid, "0") != 0 && argv[0] != NULL)
        create_new_thread(argv, msg, cli);
    msg->command = CREATE;
    return (1);
}
