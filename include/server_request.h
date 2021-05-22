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
void list_info(server_t *server, int client, request_t *request);
void request_code(int fd, int code);
void login(server_t *server, int client, request_t *request);

// Teams
void add_team(server_t *server, create_t *create, int client);
void get_teams_infos(server_t *server, int client);

//Channels
void add_channel(server_t *server, create_t *create, int client);
void get_channel_info(server_t *server, info_t *info, int client);

//Threads
void add_thread(server_t *server, create_t *create, int client);
void get_thread_info(server_t *server, info_t *info, int client);

//Messages
void add_message(server_t *server, create_t *create, int client);
void get_messages_info(server_t *server, info_t *create, int client);

typedef struct request_function_s
{
    command command;
    void (*fct) (server_t *server, int client, request_t *request);
} request_function_t;

static const request_function_t request_list[] = {
    {.command = CREATE, .fct = &create},
    {.command = LIST, .fct = &list_info},
    {.command = INFO, .fct = &list_info},
    {.command = LOGIN, .fct = &login}
    };

#endif /* !SERVER_REQUEST_H_ */
