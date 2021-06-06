/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_resp_login
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "communication.h"
#include "cli.h"
#include "logging_client.h"

Test(response_login, response_login_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    rcv->code = 201;
    strcpy(rcv->user.users->name, "BliTz");
    strcpy(rcv->user.users->uuid, generate_uuid());
    response_login(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(response_logout, response_logout_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    strcpy(rcv->user.users->name, "BliTz");
    strcpy(rcv->user.users->uuid, generate_uuid());
    response_logout(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}