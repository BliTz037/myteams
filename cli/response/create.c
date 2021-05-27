/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** create
*/

#include "communication.h"
#include "cli.h"
#include "logging_client.h"

void response_create(cli_t *cli, response_t *rcv)
{
    (void) cli;
    switch (TEAMS) {
        case (TEAMS):
            client_event_team_created(rcv->create.teams[0].team_uuid,
            rcv->create.teams[0].team_name, 
            rcv->create.teams[0].team_description);
            break;
        case (CHANNEL):
            client_print_channel_created(rcv->create.channel[0].team_uuid,
            rcv->create.channel[0].channel_name, 
            rcv->create.channel[0].channel_description);
            break;
        case (THREAD):
            client_print_thread_created("thread_uuid", "user_uuid", 
            rcv->create.thread[0].timestamp, rcv->create.thread[0].thread_title,
            rcv->create.thread[0].thread_message);
            break;
        case (MESSAGE):
            client_print_reply_created(rcv->create.comments[0].thread_uuid,
            rcv->create.comments[0].user_uuid, 
            rcv->create.comments[0].timestamp, rcv->create.comments[0].body);
            break;
    }
    return;
}