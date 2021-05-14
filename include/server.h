/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <netinet/in.h>
#include "server_client.h"

#define MAX_CLIENTS 30

typedef struct server_t server_t;
struct server_t
{
    struct sockaddr_in address;
    fd_set readfds;
    client_t clients[MAX_CLIENTS];
    int control_socket;
    int address_size;
};

int launch_server(int port);
int init_server(server_t *server, int port);
void close_connection(server_t *server, int fd, int client);
char *get_command_buffer(server_t *server, int client, char input[1024]);
int handle_commands(server_t *server, char *message, int client);

#endif /* !SERVER_H_ */
