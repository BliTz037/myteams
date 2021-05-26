/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** messages
*/

#include "communication.h"
#include "cli.h"

void response_messages(cli_t *cli, response_t *rcv)
{
    for (int i = 0; i != MAX_PM; i++)
    {
        if (strlen(rcv->message.messages[i].message) > 0)
        {
            client_private_message_print_messages(rcv->message.user_uuid,
            rcv->message.messages[i].timestamp, rcv->message.messages[i].message);
        }
    }
    return;
}