/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** error
*/

#include <stdio.h>
#include "../libs/myteams/logging_client.h"

void manage_error_response(int code)
{
    if (code == 500)
        printf("500 Internal Error\n");
    if (code == 403)
        client_error_unauthorized();
    if (code == 405)
        printf("Error 405 : You are already logged !\n");
    if (code == 410)
        client_error_already_exist();
}