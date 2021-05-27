/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** error
*/

#include <stdio.h>
#include "../libs/myteams/logging_client.h"
#include "communication.h"

void manage_error_404(response_t *rcv)
{
    int (*cmd[])(char const *) = {client_error_unknown_team,
    client_error_unknown_channel, client_error_unknown_thread,
    client_error_unknown_user};

    cmd[rcv->error_404.type](rcv->error_404.uuid);
}

void manage_error_response(response_t *rcv)
{
    if (rcv->code == 500)
        printf("500 Internal Error\n");
    if (rcv->code == 403)
        client_error_unauthorized();
    if (rcv->code == 405)
        printf("Error 405 : You are already logged !\n");
    if (rcv->code == 404)
        manage_error_404(rcv);
    if (rcv->code == 410)
        client_error_already_exist();
}
