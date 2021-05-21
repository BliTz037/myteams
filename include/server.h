/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <netinet/in.h>
#include <stdio.h>
#include "server_client.h"
#include "teams.h"

typedef struct thread_t
{
    char uuid[36];
    char message[MAX_COMMENTS];
    char comments[MAX_COMMENTS][MAX_BODY_LENGTH];
    char title[MAX_NAME_LENGTH];
} thread_t;

typedef struct channel_t
{
    char uuid[36];
    thread_t threads[MAX_THREADS];
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} channel_t;

typedef struct teams_t
{
    char uuid[36];
    channel_t channels[MAX_CHANNEL];
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} teams_t;

typedef struct server_t
{
    struct sockaddr_in address;
    fd_set readfds;
    client_t clients[MAX_CLIENTS];
    int control_socket;
    int address_size;
    teams_t teams[MAX_TEAMS];
} server_t;

int launch_server(int port);
int init_server(server_t *server, int port);
void close_connection(server_t *server, int fd, int client);
char *generate_uuid();

//Data handling
int save_data(const char *path, server_t *server);
int load_data(const char *path, server_t *server);

#endif /* !SERVER_H_ */
