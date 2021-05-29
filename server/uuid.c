/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** uuid
*/

#include "uuid/uuid.h"
#include "teams.h"
#include <stdlib.h>
#include <string.h>

char *generate_uuid()
{
    char *uuid = malloc(UUID_SIZE);
    uuid_t uuid_s;

    uuid_generate(uuid_s);
    uuid_unparse(uuid_s, uuid);
    uuid[UUID_SIZE] = '\0';
    return uuid;
}