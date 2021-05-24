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
    if (connect(cli->sockfd, (struct sockaddr *)&cli->serv_addr,
    sizeof(cli->serv_addr)) < 0) {
        printf("Failed to connect to server %s:%d\n", ip, port);
        return -1;
    }
    printf("Connected to server %s:%d\n", ip, port);
    return 0;
}

int send_message(cli_t *cli)
{
    request_t *msg = malloc(sizeof(request_t));

    if (msg == NULL)
        return (0);
    if (fill_request_struct(get_command_line(), msg, cli) != 1) {
        free(msg);
        return -1;
    }
    printf("team: '%s'\n", cli->context.team_uuid);
    printf("\tchannel: '%s'\n", cli->context.channel_uuid);
    printf("\t\tthread: '%s'\n", cli->context.thread_uuid);
    display(msg);
    write(cli->sockfd, msg, sizeof(request_t));
    printf("Message envoyer\n");
    free(msg);
    return (1);
}

int receive_message(cli_t *cli)
{
    int valread;
    response_t *resp = malloc(sizeof(response_t));

    printf("read response of size %ld\n", sizeof(infos_response_t));
    valread = read(cli->sockfd, resp, sizeof(response_t));
    printf("ON A UN MESSAGE !\n");
    if (valread == 0)
        printf("Connection Lost\n");
    free(resp);
    return (valread);
}

cli_t init_cli(cli_t cli)
{
    strcpy(cli.context.team_uuid, "0");
    strcpy(cli.context.channel_uuid, "0");
    strcpy(cli.context.thread_uuid, "0");
    return (cli);
}

int client_loop(const char *ip, const int port)
{
    cli_t cli = init_cli(cli);
    fd_set fds;
    int rcv = 1;

    if (connect_server(ip, port, &cli) < 0)
        return 84;
    while (1) {
        printf("> ");
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(cli.sockfd, &fds);
        fflush(NULL);
        if (select(cli.sockfd + 1, &fds, NULL, NULL, NULL) <= 0)
            return (-1);
        if (FD_ISSET(STDIN_FILENO, &fds))
            send_message(&cli);
        else if (FD_ISSET(cli.sockfd, &fds))
            rcv = receive_message(&cli);
        if (rcv == 0)
            break;
    }
    return (0);
}
