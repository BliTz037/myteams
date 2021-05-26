/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** socket
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
    if (connect(cli->sockfd, (struct sockaddr *)&cli->serv_addr,
    sizeof(cli->serv_addr)) < 0) {
        printf("Failed to connect to server %s:%d\n", ip, port);
        return -1;
    }
    printf("Connected to server %s:%d\n", ip, port);
    return 0;
}

int init_select(cli_t *cli, fd_set *fds)
{
    FD_ZERO(fds);
    FD_SET(STDIN_FILENO, fds);
    FD_SET(cli->sockfd, fds);
    fflush(NULL);
    if (select(cli->sockfd + 1, fds, NULL, NULL, NULL) <= 0)
        return (-1);
    return (0);
}