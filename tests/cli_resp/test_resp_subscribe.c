/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_resp_subscribe
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "communication.h"
#include "cli.h"

Test(response_subscribe, response_subscribe_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    strcpy(rcv->subscribe.user_uuid, generate_uuid());
    strcpy(rcv->subscribe.team_uuid, generate_uuid());
    response_subscribe(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(response_unsubscribe, response_unsubscribe_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    strcpy(rcv->subscribe.user_uuid, generate_uuid());
    strcpy(rcv->subscribe.team_uuid, generate_uuid());
    response_unsubscribed(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(response_subscribed, response_subscribed_teams_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    strcpy(rcv->subscribed.teams[0].team_name, "team");
    strcpy(rcv->subscribed.teams[0].team_description, "desc");
    strcpy(rcv->subscribed.teams[0].team_uuid, generate_uuid());
    response_subscribed(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(response_subscribed, response_subscribed_user_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    strcpy(rcv->subscribed.users[0].name, "team");
    strcpy(rcv->subscribed.users[0].uuid, generate_uuid());
    rcv->subscribed.users[0].status = 1;
    response_subscribed(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}