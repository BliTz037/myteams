/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** create
*/

#include "communication.h"
#include "cli.h"
#include "logging_client.h"

static void response_single_user(response_t *rcv)
{
    if (rcv->create.type == TEAMS)
        client_print_team_created(rcv->create.teams[0].team_uuid,
        rcv->create.teams[0].team_name, 
        rcv->create.teams[0].team_description);
    if (rcv->create.type == CHANNEL)
        client_print_channel_created(rcv->create.channel[0].team_uuid,
        rcv->create.channel[0].channel_name, 
        rcv->create.channel[0].channel_description);
    if (rcv->create.type == THREAD)
        client_print_thread_created(rcv->create.thread[0].thread_uuid,
        rcv->create.thread[0].user_uuid, rcv->create.thread[0].timestamp,
        rcv->create.thread[0].thread_title,
        rcv->create.thread[0].thread_message);
    if (rcv->create.type == MESSAGE)
        client_print_reply_created(rcv->create.comments[0].thread_uuid,
        rcv->create.comments[0].user_uuid, rcv->create.comments[0].timestamp,
        rcv->create.comments[0].body);
}

static void response_all_users(response_t *rcv)
{
    if (rcv->create.type == TEAMS)
        client_event_team_created(rcv->create.teams[0].team_uuid,
        rcv->create.teams[0].team_name, 
        rcv->create.teams[0].team_description);
    if (rcv->create.type == CHANNEL)
        client_event_channel_created(rcv->create.channel[0].team_uuid,
        rcv->create.channel[0].channel_name, 
        rcv->create.channel[0].channel_description);
    if (rcv->create.type == THREAD)
        client_event_thread_created(rcv->create.thread[0].thread_uuid,
        rcv->create.thread[0].user_uuid, rcv->create.thread[0].timestamp,
        rcv->create.thread[0].thread_title,
        rcv->create.thread[0].thread_message);
    if (rcv->create.type == MESSAGE)
        client_event_thread_reply_received(rcv->create.comments[0].team_uuid,
        rcv->create.comments[0].thread_uuid, rcv->create.comments[0].user_uuid,
        rcv->create.comments[0].body);
}

void response_create(cli_t *cli, response_t *rcv)
{
    (void) cli;
    if (rcv->create.is_global_ping == 1)
        response_all_users(rcv);
    else
        response_single_user(rcv);
}
