/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_cli_cmd_list
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cli.h"

void redirect_all_std(void);

Test(command_list, command_list_user_test)
{
    char *argv[2] = {"toto", "desc"};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    command_list(argv, msg, cli);
    cr_assert_eq(msg->info.type, TEAMS);
    free(msg);
    free(cli);
}

Test(command_list, command_list_teams_test)
{
    char *argv[2] = {"toto", "desc"};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    strcpy(cli->context.team_uuid, generate_uuid());
    command_list(argv, msg, cli);
    cr_assert_eq(msg->info.type, CHANNEL);
    free(msg);
    free(cli);
}

Test(command_list, command_list_channel_test)
{
    char *argv[2] = {"toto", "desc"};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    strcpy(cli->context.team_uuid, generate_uuid());
    strcpy(cli->context.channel_uuid, generate_uuid());
    command_list(argv, msg, cli);
    cr_assert_eq(msg->info.type, THREAD);
    free(msg);
    free(cli);
}

Test(command_list, command_list_thread_test)
{
    char *argv[2] = {"toto", "desc"};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    strcpy(cli->context.team_uuid, generate_uuid());
    strcpy(cli->context.channel_uuid, generate_uuid());
    strcpy(cli->context.thread_uuid, generate_uuid());
    command_list(argv, msg, cli);
    cr_assert_eq(msg->info.type, MESSAGE);
    free(msg);
    free(cli);
}