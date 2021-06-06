/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_resp_info
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "communication.h"
#include "cli.h"
#include "logging_client.h"

Test(resp_info, resp_info_users_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    rcv->infos.type = USER_INFO;
    strcpy(rcv->user.users[0].name, "abc");
    rcv->user.users[0].status = 1;
    strcpy(rcv->user.users[0].uuid, generate_uuid());
    response_info(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(resp_info, resp_info_teams_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    rcv->infos.type = TEAMS;
    strcpy(rcv->infos.teams[0].team_name, "abc");
    strcpy(rcv->infos.teams[0].team_description, "desc");
    strcpy(rcv->infos.teams[0].team_uuid, generate_uuid());
    response_info(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(resp_info, resp_info_channel_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    rcv->infos.type = CHANNEL;
    strcpy(rcv->infos.channel[0].channel_name, "abc");
    strcpy(rcv->infos.channel[0].channel_description, "desc");
    strcpy(rcv->infos.channel[0].team_uuid, generate_uuid());
    response_info(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(resp_info, resp_info_thread_test)
{
    response_t *rcv = malloc(sizeof(response_t));
    time_t timestamp = time(NULL);

    rcv->infos.type = THREAD;
    strcpy(rcv->infos.thread[0].thread_title, "abc");
    strcpy(rcv->infos.thread[0].thread_message, "msg");
    strcpy(rcv->infos.thread[0].thread_uuid, generate_uuid());
    strcpy(rcv->infos.thread[0].user_uuid, generate_uuid());
    rcv->infos.thread[0].timestamp = timestamp;
    response_info(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}