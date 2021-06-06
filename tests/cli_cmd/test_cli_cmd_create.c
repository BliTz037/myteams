/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_cli_resp_create
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cli.h"

Test(command_create, command_create_team_test)
{
    char *argv[2] = {"toto", "desc"};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    cr_assert_eq(command_create(argv, msg, cli), 1);
    free(msg);
    free(cli);
}

Test(command_create, command_create_channel_test)
{
    char *argv[2] = {"toto", "desc"};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    strcpy(cli->context.team_uuid, generate_uuid());
    cr_assert_eq(command_create(argv, msg, cli), 1);
    free(msg);
    free(cli);
}

Test(command_create, command_create_thread_test)
{
    char *argv[2] = {"toto", "desc"};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    strcpy(cli->context.team_uuid, generate_uuid());
    strcpy(cli->context.channel_uuid, generate_uuid());
    cr_assert_eq(command_create(argv, msg, cli), 1);
    free(msg);
    free(cli);
}

Test(command_create, command_create_reply_test)
{
    char *argv[2] = {"toto", "desc"};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    strcpy(cli->context.team_uuid, generate_uuid());
    strcpy(cli->context.channel_uuid, generate_uuid());
    strcpy(cli->context.thread_uuid, generate_uuid());
    cr_assert_eq(command_create(argv, msg, cli), 1);
    free(msg);
    free(cli);
}
