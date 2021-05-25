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
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "communication.h"

#define PATH_COMMAND_HELP "file/help_command.txt"

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

int command_login(char **argv, request_t *msg, cli_t *cli);
int command_logout(char **argv, request_t *msg, cli_t *cli);
int command_user(char **argv, request_t *msg, cli_t *cli);
int command_send(char **argv, request_t *msg, cli_t *cli);
int command_messages(char **argv, request_t *msg, cli_t *cli);
int command_subscribe(char **argv, request_t *msg, cli_t *cli);
int command_subscribed(char **argv, request_t *msg, cli_t *cli);
int command_unsubscribed(char **argv, request_t *msg, cli_t *cli);
int command_create(char **argv, request_t *msg, cli_t *cli);
int command_list(char **argv, request_t *msg, cli_t *cli);
int command_info(char **argv, request_t *msg, cli_t *cli);
int command_use(char **argv, request_t *msg, cli_t *cli);
int command_help(char **argv, request_t *msg, cli_t *cli);

void response_login(cli_t *cli, response_t *rcv);
void response_logout(cli_t *cli, response_t *rcv);
void response_user(cli_t *cli, response_t *rcv);
void response_send(cli_t *cli, response_t *rcv);
void response_messages(cli_t *cli, response_t *rcv);
void response_subscribe(cli_t *cli, response_t *rcv);
void response_subscribed(cli_t *cli, response_t *rcv);
void response_unsubscribed(cli_t *cli, response_t *rcv);
void response_create(cli_t *cli, response_t *rcv);
void response_list(cli_t *cli, response_t *rcv);
void response_info(cli_t *cli, response_t *rcv);

int receive_message(cli_t *cli);
int send_message(cli_t *cli);
int connect_server(const char *ip, const int port, cli_t *cli);
void translate_response(cli_t *cli, response_t *res);
void manage_error_response(int code);

char *get_command_line(void);
char **str_to_word_array(char *str, const char *delim, int *len);
void free_world_arr(char **tab, const int len);
int fill_request_struct(char *command, request_t *msg, cli_t *cli);

cli_t init_cli(cli_t cli);
int client_loop(const char *ip, const int port);
int connect_server(const char *ip, const int port, cli_t *cli);
void display(request_t *msg);
int print_help(char *av);
int send_message(cli_t *cli);

#endif /* !CLI_H_ */
