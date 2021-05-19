/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server_client
*/

#ifndef SERVER_CLIENT_H_
#define SERVER_CLIENT_H_

#include <netinet/in.h>

typedef struct client_t client_t;
struct client_t
{
    struct sockaddr_in data_address;
    int socket;
    int uuid;
};

#endif