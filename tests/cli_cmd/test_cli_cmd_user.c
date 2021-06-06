/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_cli_cmd_user
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cli.h"

Test(command_users, command_users_test)
{
    char *argv[1] = {NULL};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    cr_assert_eq(command_users(argv, msg, cli), 1);
    free(msg);
    free(cli);
}

Test(command_user, command_user_test)
{
    char *argv_null[1] = {NULL};
    char *argv[1] = {generate_uuid()};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    cr_assert_eq(command_user(argv_null, msg, cli), 0);
    cr_assert_eq(command_user(argv, msg, cli), 1);
    free(msg);
    free(cli);
}