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

void get_client_request(server_t *server, int sd, int client);
void handle_request(server_t *server, int client, request_t *request);
void create(server_t *server, int client, request_t *request);
void list(server_t *server, int client, request_t *request);
void info(server_t *server, int client, request_t *request);
void request_code(int fd, int code);
void request_404_error(int fd, char *uuid, service_type type);
void login(server_t *server, int client, request_t *request);
void logout(server_t *server, int client, request_t *request);
void subscribe(server_t *server, int client, request_t *request);
void unsubscribe(server_t *server, int client, request_t *request);
void subscribed(server_t *server, int client, request_t *request);
void list_user_in_team(server_t *server, int client, char *team_uuid);
int check_subscribed_request(int fd, char *user_uuid, teams_t *team);
void user(server_t *server, int client, request_t *request);
void my_send(server_t *server, int client, request_t *request);
void get_current_logged_infos(server_t *server, int fd);
void messages(server_t *server, int client, request_t *request);
int is_subscribed_to_team(teams_t *team, char *uuid);

// Teams
void add_team(server_t *server, create_t *create, int client);
void get_teams_list(server_t *server, int client);
void get_teams_info(server_t *server, int client, info_t *info);

//Channels
void add_channel(server_t *server, create_t *create, int client);
void get_channel_info(server_t *server, info_t *info, int client);
void get_channel_list(server_t *server, info_t *info, int client);

//Threads
void add_thread(server_t *server, create_t *create, int client);
void get_thread_list(server_t *server, info_t *info,
int client);
void get_thread_info(server_t *server, info_t *info,
int client);

//Messages
void add_message(server_t *server, create_t *create, int client);
void get_messages_list(server_t *server, info_t *create,
int client);
void message_notify_all_users(server_t *server, teams_t *team,
comment_t *message, message_manipulation_t *message_info);

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
    {.command = LOGOUT, .fct = &logout},
    {.command = SUBSCRIBE, .fct = &subscribe},
    {.command = UNSUBSCRIBE, .fct = &unsubscribe},
    {.command = SUBSCRIBED, .fct = &subscribed},
    {.command = USER, .fct = &user},
    {.command = MESSAGES, .fct = &messages},
    {.command = SEND, .fct = &my_send},
    };

#endif /* !SERVER_REQUEST_H_ */
