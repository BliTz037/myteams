/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_resp_create
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "communication.h"
#include "cli.h"
#include "logging_client.h"

Test(resp_create, resp_create_teams_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    rcv->create.type = TEAMS;
    rcv->create.is_global_ping = 0;
    strcpy(rcv->create.teams[0].team_name, "abc");
    strcpy(rcv->create.teams[0].team_description, "desc");
    strcpy(rcv->create.teams[0].team_uuid, generate_uuid());
    response_create(rcv);
    rcv->create.is_global_ping = 0;
    response_create(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(resp_create, resp_create_channel_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    rcv->create.type = CHANNEL;
    rcv->create.is_global_ping = 0;
    strcpy(rcv->create.channel[0].channel_name, "abc");
    strcpy(rcv->create.channel[0].channel_description, "desc");
    strcpy(rcv->create.channel[0].team_uuid, generate_uuid());
    response_create(rcv);
    rcv->create.is_global_ping = 0;
    response_create(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(resp_create, resp_create_thread_test)
{
    response_t *rcv = malloc(sizeof(response_t));
    time_t timestamp = time(NULL);

    rcv->create.type = THREAD;
    rcv->create.is_global_ping = 0;
    strcpy(rcv->create.thread[0].thread_title, "abc");
    strcpy(rcv->create.thread[0].thread_message, "desc");
    strcpy(rcv->create.thread[0].thread_uuid, generate_uuid());
    strcpy(rcv->create.thread[0].user_uuid, generate_uuid());
    rcv->create.thread[0].timestamp = timestamp;
    response_create(rcv);
    rcv->create.is_global_ping = 0;
    response_create(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(resp_create, resp_create_message_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    rcv->create.type = MESSAGE;
    rcv->create.is_global_ping = 0;
    strcpy(rcv->create.comments[0].team_uuid, generate_uuid());
    strcpy(rcv->create.comments[0].thread_uuid, generate_uuid());
    strcpy(rcv->create.comments[0].user_uuid, generate_uuid());
    strcpy(rcv->create.comments[0].body, "test");
    response_create(rcv);
    rcv->create.is_global_ping = 0;
    response_create(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}