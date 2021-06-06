/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_cli_cmd_msg
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cli.h"

Test(command_message, command_msg_test)
{
    char *argv[2] = {generate_uuid(), NULL};
    char *argv_null[2] = {NULL, NULL};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    cr_assert_eq(command_messages(argv_null, msg, cli), 0);
    cr_assert_eq(command_messages(argv, msg, cli), 1);
    free(msg);
    free(cli);
}

Test(command_send, command_send_test)
{
    char *argv[2] = {generate_uuid(), "Hello"};
    char *argv_null[2] = {NULL, NULL};
    request_t *msg = malloc(sizeof(response_t));
    cli_t *cli = malloc(sizeof(cli_t));

    cr_assert_eq(command_send(argv_null, msg, cli), 0);
    cr_assert_eq(command_send(argv, msg, cli), 1);
    free(msg);
    free(cli);
}