/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_resp_user
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "communication.h"
#include "cli.h"

Test(response_user, response_user_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    strcpy(rcv->user.users[0].name, "user");
    strcpy(rcv->user.users[0].uuid, generate_uuid());
    rcv->user.users[0].status = 1;
    response_user(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(response_users, response_users_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    strcpy(rcv->user.users[0].name, "user");
    strcpy(rcv->user.users[0].uuid, generate_uuid());
    rcv->user.users[0].status = 1;
    response_users(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}