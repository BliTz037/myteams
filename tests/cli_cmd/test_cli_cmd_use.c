/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_cli_cmd_use
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cli.h"

void use_thread(char **argv, cli_t *cli);

Test(command_use, command_use_null_test)
{
    char *argv_null[1] = {NULL};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    command_use(argv_null, msg, cli);
    cr_assert_str_eq(cli->context.team_uuid, "\0");
    cr_assert_str_eq(cli->context.channel_uuid, "\0");
    cr_assert_str_eq(cli->context.thread_uuid, "\0");
    free(msg);
    free(cli);
}

Test(command_use, command_use_team_test)
{
    char *argv[3] = {generate_uuid(), NULL, NULL};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    command_use(argv, msg, cli);
    cr_assert_str_eq(cli->context.team_uuid, argv[0]);
    free(msg);
    free(cli);
}

Test(command_use, command_use_channel_test)
{
    char *argv[3] = {generate_uuid(), generate_uuid(), generate_uuid()};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    command_use(argv, msg, cli);
    cr_assert_str_eq(cli->context.team_uuid, argv[0]);
    cr_assert_str_eq(cli->context.channel_uuid, argv[1]);
    free(msg);
    free(cli);
}

Test(command_use, command_use_thread_test)
{
    char *argv[3] = {generate_uuid(), generate_uuid(), generate_uuid()};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    use_thread(argv, cli);
    cr_assert_str_eq(cli->context.team_uuid, argv[0]);
    cr_assert_str_eq(cli->context.channel_uuid, argv[1]);
    cr_assert_str_eq(cli->context.thread_uuid, argv[2]);
    free(msg);
    free(cli);
}