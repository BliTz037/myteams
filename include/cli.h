/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** cli
*/

#ifndef CLI_H_
#define CLI_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "communication.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static char *commmand_str[] =
    {"/LOGIN", "/LOGOUT", "/USER", "/SEND",
    "/MESSAGES", "/SUBSCRIBE", "/SUBSCRIBED",
    "/UNSUBSCRIBE", "/CREATE", "/LIST", "/INFO"};

typedef struct cli
{
    int sockfd;
    struct sockaddr_in serv_addr;
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
char **str_to_word_array(char *src, char *separator);
int fill_request_struct(char *command, request_t *msg);

int client_loop(const char *ip, const int port);
int connect_server(const char *ip, const int port, cli_t *cli);
void display(request_t *msg);
int print_help(char *av);
int send_message(request_t *msg);

#endif /* !CLI_H_ */
