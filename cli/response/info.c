/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** info
*/

#include "communication.h"
#include "cli.h"
#include "logging_client.h"

void response_info(cli_t *cli, response_t *rcv)
{
    (void) cli;
    switch (rcv->infos.type){
        case (USER_INFO):
            client_print_user(rcv->user.users[0].uuid,
            rcv->user.users[0].name, rcv->user.users[0].status);
            break;
        case (TEAMS):
            client_print_team(rcv->infos.teams[0].team_uuid,
            rcv->infos.teams[0].team_name,
            rcv->infos.teams[0].team_description);
            break;
        case (CHANNEL):
            client_print_channel(rcv->infos.channel[0].team_uuid,
            rcv->infos.channel[0].channel_name,
            rcv->infos.channel[0].channel_description);
            break;
        case (THREAD):
            client_print_thread("thread uuid", "user_uuid", 
            rcv->infos.thread[0].timestamp, rcv->infos.thread[0].thread_title,
            rcv->infos.thread[0].thread_message);
            break;
    }
}