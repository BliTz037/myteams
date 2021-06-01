/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** list
*/

#include "communication.h"
#include "cli.h"
#include "logging_client.h"

void display_team(response_t *rcv)
{
    for (int i = 0; i != MAX_TEAMS; i++)
    {
        printf("Len: %ld\n", strlen(rcv->infos.teams[i].team_name));
        if (strlen(rcv->infos.teams[i].team_name) > 0)
        {
            printf("rcv->infos.teams[i].team_uuid : %s\n", rcv->infos.teams[i].team_uuid);
            client_print_team(rcv->infos.teams[i].team_uuid,
            rcv->infos.teams[i].team_name,
            rcv->infos.teams[i].team_description);
        }
    }
}

void display_channel(response_t *rcv)
{
    for (int i = 0; i != MAX_CHANNEL; i++)
    {
        if (strlen(rcv->infos.channel[i].channel_name) > 0)
        {
            client_print_channel(rcv->infos.channel[i].team_uuid,
            rcv->infos.channel[i].channel_name,
            rcv->infos.channel[i].channel_description);
        }
    }
}

void display_thread(response_t *rcv)
{
    for (int i = 0; i != MAX_THREADS; i++)
    {
        if (strlen(rcv->infos.thread[i].thread_title) > 0)
        {
            client_print_thread(rcv->infos.thread[i].thread_uuid,
            rcv->infos.thread[i].user_uuid, rcv->infos.thread[i].timestamp,
            rcv->infos.thread[i].thread_title,
            rcv->infos.thread[i].thread_message);
        }
    }
}

void display_replies(response_t *rcv)
{
    for (int i = 0; i != MAX_COMMENTS; i++)
    {
        if (strlen(rcv->infos.comments[i].body) > 0)
        {
            client_thread_print_replies(rcv->infos.comments[i].thread_uuid,
            rcv->infos.comments[i].user_uuid, rcv->infos.comments[i].timestamp,
            rcv->infos.comments[i].body);
        }
    }
}

void response_list(cli_t *cli, response_t *rcv)
{
    (void)(cli);
    switch (rcv->infos.type){
        case (TEAMS):
            display_team(rcv);
            break;
        case (CHANNEL):
            display_channel(rcv);
            break;
        case (THREAD):
            display_thread(rcv);
            break;
        case (MESSAGE):
            display_replies(rcv);
            break;
    }
}