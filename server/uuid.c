/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** uuid
*/

#include "uuid/uuid.h"
#include <stdlib.h>

char *generate_uuid()
{
    char *uuid = malloc(36);
    uuid_t uuid_s;

    uuid_generate(uuid_s);
    uuid_unparse(uuid_s, uuid);
    return uuid;
}