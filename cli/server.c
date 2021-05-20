/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server
*/

#include "cli.h"

int connect_server(const char *ip, const int port, cli_t *cli)
{
    cli->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (cli->sockfd < 0)
        return -1;
    cli->serv_addr.sin_family = AF_INET;
    cli->serv_addr.sin_port = htons(port);
    cli->serv_addr.sin_addr.s_addr = inet_addr(ip);
    if (connect(cli->sockfd, (struct sockaddr *)&cli->serv_addr, sizeof(cli->serv_addr)) < 0) {
        printf("Connection FAIL\n");
        return -1;
    }
    printf("Connection OK\n");
    return 0;
}

int send_message(request_t *msg)
{
    if (msg != NULL) {
        display(msg);
        return (1);
    }
    return (0);
}

int client_loop(const char *ip, const int port)
{
    request_t *msg = malloc(sizeof(request_t));
    cli_t cli;

    if (connect_server(ip, port, &cli) < 0)
        return -1;
    while (1) {
        if (fill_request_struct(get_command_line(), msg) == 1)
            send_message(msg);
    }
}