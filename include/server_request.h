/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server_request
*/

#ifndef SERVER_REQUEST_H_
#define SERVER_REQUEST_H_

#include "communication.h"
#include "server.h"

void handle_request(server_t *server, int client, request_t *request);
void create(server_t *server, int client, request_t *request);
void list(server_t *server, int client, request_t *request);
void info(server_t *server, int client, request_t *request);

// Teams
void addTeam(server_t *server, create_t *create, int client);

//Channels
void addChannel(server_t *server, create_t *create, int client);

//Threads
void addThread(server_t *server, create_t *create, int client);

//Messages
void addMessage(server_t *server, create_t *create, int client);

typedef struct request_function_s
{
    command command;
    void (*fct) (server_t *server, int client, request_t *request);
} request_function_t;

static const request_function_t request_list[] = {
    {.command = CREATE, .fct = &create},
    {.command = LIST, .fct = &list},
    {.command = INFO, .fct = &info}
    };

#endif /* !SERVER_REQUEST_H_ */
