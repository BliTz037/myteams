/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** send
*/

#include "communication.h"
#include "../libs/myteams/logging_client.h"
#include "cli.h"

void response_send(cli_t *cli, response_t *rcv)
{
    (void)(rcv);

    client_event_private_message_received(rcv->message.user_uuid,
    rcv->message.messages[0].message);
}