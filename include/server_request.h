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
void request_code(int fd, int code);
void login(server_t *server, int client, request_t *request);
void subscribe(server_t *server, int client, request_t *request);
void unsubscribe(server_t *server, int client, request_t *request);
void subscribed(server_t *server, int client, request_t *request);
int check_subscribed_request(int fd, char *user_uuid, teams_t *team);

// Teams
void add_team(server_t *server, create_t *create, int client);
void get_teams_infos(server_t *server, int client, command command);

//Channels
void add_channel(server_t *server, create_t *create, int client);
void get_channel_info(server_t *server, info_t *info, int client, command command);

//Threads
void add_thread(server_t *server, create_t *create, int client);
void get_thread_info(server_t *server, info_t *info, int client, command command);

//Messages
void add_message(server_t *server, create_t *create, int client);
void get_messages_info(server_t *server, info_t *create, int client, command command);

typedef struct request_function_s
{
    command command;
    void (*fct) (server_t *server, int client, request_t *request);
} request_function_t;

static const request_function_t request_list[] = {
    {.command = CREATE, .fct = &create},
    {.command = LIST, .fct = &list},
    {.command = INFO, .fct = &info},
    {.command = LOGIN, .fct = &login},
    {.command = SUBSCRIBE, .fct = &subscribe},
    {.command = UNSUBSCRIBE, .fct = &unsubscribe},
    {.command = SUBSCRIBED, .fct = &subscribed},
    };

#endif /* !SERVER_REQUEST_H_ */
