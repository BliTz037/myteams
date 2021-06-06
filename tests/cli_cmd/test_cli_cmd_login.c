/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_cli_cmd_login
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cli.h"

void redirect_all_std(void);

Test(command_login, command_login_test)
{
    char *argv[2] = {"toto", "desc"};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    command_login(argv, msg, cli);
    cr_assert_eq(msg->command, LOGIN);
    cr_assert_str_eq(msg->login.username, argv[0]);
    free(msg);
    free(cli);
}

Test(command_logout, command_logout_test)
{
    char *argv[2] = {"toto", "desc"};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    command_logout(argv, msg, cli);
    cr_assert_eq(msg->command, LOGOUT);
    free(msg);
    free(cli);
}