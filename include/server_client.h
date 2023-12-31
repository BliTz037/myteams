/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server_client
*/

#ifndef SERVER_CLIENT_H_
#define SERVER_CLIENT_H_

#include <netinet/in.h>
#include "teams.h"

typedef struct private_message_body_s
{
    char message[MAX_BODY_LENGTH];
    time_t timestamp;
} private_message_body_t;

typedef struct private_message_s
{
    private_message_body_t messages[MAX_PM];
    char user_uuid[UUID_SIZE];
} private_message_t;

typedef struct client_t client_t;
struct client_t
{
    char uuid[UUID_SIZE];
    struct sockaddr_in data_address;
    int socket;
    char name[MAX_NAME_LENGTH];
    int loged;
    private_message_t private_messages[MAX_CLIENTS];
};

#endif