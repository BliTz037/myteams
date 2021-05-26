/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** subscribed
*/

#include "communication.h"
#include "../libs/myteams/logging_client.h"
#include "cli.h"

static void print_users(response_t *rcv)
{
    for (int i = 0; i != MAX_CLIENTS; i++) {
        if (rcv->subscribed.users[i].name[0] != '\0')
            client_print_users(rcv->subscribed.users[i].uuid,
            rcv->subscribed.users[i].name,
            rcv->subscribed.users[i].status);
    }
}

static void print_teams(response_t *rcv)
{
    for (int i = 0; i != MAX_TEAMS; i++) {
        if (rcv->subscribed.teams[i].team_uuid[0] != '\0')
            client_print_teams(rcv->subscribed.teams[i].team_uuid,
            rcv->subscribed.teams[i].team_name,
            rcv->subscribed.teams[i].team_description);
    }
}

void response_subscribed(cli_t *cli, response_t *rcv)
{
    (void)(cli);
    if (rcv->subscribed.teams[0].team_name[0] != '\0')
        print_teams(rcv);
    else
        print_users(rcv);
}