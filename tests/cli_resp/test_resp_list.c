/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_resp_list
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "communication.h"
#include "logging_client.h"
#include "cli.h"

Test(resp_list, resp_list_teams_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    rcv->infos.type = TEAMS;
    rcv->infos.nb = 1;
    strcpy(rcv->infos.teams[0].team_name, "abc");
    strcpy(rcv->infos.teams[0].team_description, "desc");
    strcpy(rcv->infos.teams[0].team_uuid, generate_uuid());
    response_list(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(resp_list, resp_list_channel_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    rcv->infos.type = CHANNEL;
    rcv->infos.nb = 1;
    strcpy(rcv->infos.channel[0].channel_name, "abc");
    strcpy(rcv->infos.channel[0].channel_description, "desc");
    strcpy(rcv->infos.channel[0].team_uuid, generate_uuid());
    response_list(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(resp_list, resp_list_thread_test)
{
    response_t *rcv = malloc(sizeof(response_t));
    time_t timestamp = time(NULL);

    rcv->infos.type = THREAD;
    rcv->infos.nb = 1;
    strcpy(rcv->infos.thread[0].thread_title, "abc");
    strcpy(rcv->infos.thread[0].thread_message, "msg");
    strcpy(rcv->infos.thread[0].thread_uuid, generate_uuid());
    strcpy(rcv->infos.thread[0].user_uuid, generate_uuid());
    rcv->infos.thread[0].timestamp = timestamp;
    response_list(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(resp_list, resp_list_message_test)
{
    response_t *rcv = malloc(sizeof(response_t));
    time_t timestamp = time(NULL);

    rcv->infos.type = MESSAGE;
    rcv->infos.nb = 1;
    strcpy(rcv->infos.comments[0].body, "msg");
    strcpy(rcv->infos.thread[0].thread_uuid, generate_uuid());
    strcpy(rcv->infos.comments[0].team_uuid, generate_uuid());
    strcpy(rcv->infos.comments[0].user_uuid, generate_uuid());
    rcv->infos.thread[0].timestamp = timestamp;
    response_list(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}