/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_resp_error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "logging_client.h"
#include "communication.h"
#include "cli.h"

Test(resp_error, resp_error_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    rcv->error_404.type = TEAMS;
    strcpy(rcv->error_404.uuid, generate_uuid());
    rcv->code = 500;
    manage_error_response(rcv);
    rcv->code = 403;
    manage_error_response(rcv);
    rcv->code = 405;
    manage_error_response(rcv);
    rcv->code = 410;
    manage_error_response(rcv);
    rcv->code = 404;
    manage_error_response(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}