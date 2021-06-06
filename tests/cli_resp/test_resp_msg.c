/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_resp_msg
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "communication.h"
#include "logging_client.h"
#include "cli.h"

Test(response_msg, response_msg_test)
{
    response_t *rcv = malloc(sizeof(response_t));
    time_t timestamp = time(NULL);

    strcpy(rcv->message.messages[0].message, "msg");
    strcpy(rcv->message.user_uuid, generate_uuid());
    rcv->message.messages[0].timestamp = timestamp;
    response_messages(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}

Test(response_send, response_send_test)
{
    response_t *rcv = malloc(sizeof(response_t));

    strcpy(rcv->message.messages[0].message, "msg");
    strcpy(rcv->message.user_uuid, generate_uuid());
    response_send(rcv);
    cr_assert_eq(0, 0);
    free(rcv);
}