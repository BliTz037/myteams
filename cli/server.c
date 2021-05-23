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

int send_message(cli_t *cli)
{
    request_t *msg = malloc(sizeof(request_t));

    if (msg == NULL)
        return (0);
    if (fill_request_struct(get_command_line(), msg) != 1)
    {
        free(msg);
        return -1;
    }
    display(msg);
    write(cli->sockfd, msg, sizeof(request_t));
    printf("Message envoyer\n");
    free(msg);
    return (1);
}

void receive_message(cli_t *cli)
{
    int valread;
    response_t *resp = malloc(sizeof(response_t));

    printf("read response of size %ld\n", sizeof(infos_response_t));
    valread = read(cli->sockfd, resp, sizeof(response_t));
    printf("valread: %d\n", valread);
    free(resp);
}

int client_loop(const char *ip, const int port)
{
    cli_t cli;
    fd_set fds;

    if (connect_server(ip, port, &cli) < 0)
        return -1;
    while (1) {
        printf("> ");
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(cli.sockfd, &fds);
        fflush(NULL);
        if (select(cli.sockfd + 1, &fds, NULL, NULL, NULL) <= 0)
            return (-1);
        if (FD_ISSET(STDIN_FILENO, &fds)) {
            send_message(&cli);
        }
        else if (FD_ISSET(cli.sockfd, &fds)) {
            printf("ON A UN MESSAGE !\n");
            receive_message(&cli);
        }
    }
}