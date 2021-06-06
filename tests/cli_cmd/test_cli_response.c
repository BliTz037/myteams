/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_cli_response
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cli.h"

Test(server, test_init_cli)
{
    cli_t cli = init_cli(cli);

    cr_assert_str_eq(cli.context.team_uuid, "\0");
    cr_assert_str_eq(cli.context.channel_uuid, "\0");
    cr_assert_str_eq(cli.context.thread_uuid, "\0");
}

Test(command, command_help_test)
{
    cr_assert_eq(command_help(NULL, NULL, NULL), 0);
}