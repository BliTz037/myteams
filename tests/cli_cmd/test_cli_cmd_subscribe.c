/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_cli_cmd_subscribe
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cli.h"

Test(command_subscribe, command_subscribe_test)
{
    char *argv[1] = {generate_uuid()};
    char *argv_null[1] = {NULL};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    cr_assert_eq(command_subscribe(argv_null, msg, cli), 0);
    cr_assert_eq(command_subscribe(argv, msg, cli), 1);
    free(msg);
    free(cli);
}

Test(command_subscribed, command_subscribed_test)
{
    char *argv[1] = {generate_uuid()};
    char *argv_null[1] = {NULL};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    cr_assert_eq(command_subscribed(argv_null, msg, cli), 0);
    cr_assert_eq(command_subscribed(argv, msg, cli), 1);
    free(msg);
    free(cli);
}

Test(command_unsubscribed, command_unsubscribed_test)
{
    char *argv[1] = {generate_uuid()};
    char *argv_null[1] = {NULL};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    cr_assert_eq(command_unsubscribed(argv_null, msg, cli), 0);
    cr_assert_eq(command_unsubscribed(argv, msg, cli), 1);
    free(msg);
    free(cli);
}