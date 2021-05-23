/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** cli
*/

#ifndef CLI_H_
#define CLI_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "communication.h"
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static char *commmand_str[] =
    {"/login", "/logout", "/user", "/send",
    "/messages", "/subscribe", "/subscribed",
    "/unsubscribe", "/create", "/list", "/info"};

// static char *HELP_CMD = '/help show help\n\
// /login ["user_name"] : set the user_name used by client\n\
// /logout : disconnect the client from the server\n\
// /users : get the list of all users that exist on the domain\n\
// /user ["user_uuid"] : get information about a user\n\
// /send ["user_uuid"] ["message_body"] : send a message to a user\n\
// /messages ["user_uuid"] : list all messages exchange with an user\n
// /subscribe ["team_uuid"] : subscribe to the event of a team and its sub directories (enable receptionof all events from a team)\n\
// /subscribed ?["team_uuid"] : list all subscribed teams or list all users subscribed to a team\n\
// /unsubscribe ["team_uuid"] : unsubscribe from a team\n\
// /use ?["team_uuid"] ?["channel_uuid"] ?["thread_uuid"] : use specify a context team/channel/thread\n\
// /create : based on what is being used create the sub resource (see below)\n\
// /list : based on what is being used list all the sub resources (see below)\n\
// /info : based on what is being used list the current (see below)\n';

typedef struct context
{
    char team_uuid[UUID_SIZE];
    char channel_uuid[UUID_SIZE];
    char thread_uuid[UUID_SIZE];
} context_t;

typedef struct cli
{
    int sockfd;
    struct sockaddr_in serv_addr;
    context_t context;
} cli_t;

void command_login(char **argv, request_t *msg);
void command_logout(char **argv, request_t *msg);
void command_user(char **argv, request_t *msg);
void command_send(char **argv, request_t *msg);
void command_messages(char **argv, request_t *msg);
void command_subscribe(char **argv, request_t *msg);
void command_subscribed(char **argv, request_t *msg);
void command_unsubscribed(char **argv, request_t *msg);
void command_create(char **argv, request_t *msg);
void command_list(char **argv, request_t *msg);
void command_info(char **argv, request_t *msg);


char *get_command_line(void);
char **str_to_word_array(char *str, const char *delim, int *len);
int fill_request_struct(char *command, request_t *msg, cli_t *cli);

int client_loop(const char *ip, const int port);
int connect_server(const char *ip, const int port, cli_t *cli);
void display(request_t *msg);
int print_help(char *av);
int send_message(cli_t *cli);

#endif /* !CLI_H_ */
