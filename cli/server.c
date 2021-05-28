/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** server
*/

#include "cli.h"

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

    valread = read(cli->sockfd, resp, sizeof(response_t));
    if (valread == 0)
        printf("Connection Lost\n");
    translate_response(cli, resp);
    free(resp);
    return (valread);
}

cli_t init_cli(cli_t cli)
{
    strcpy(cli.context.team_uuid, "\0");
    strcpy(cli.context.channel_uuid, "\0");
    strcpy(cli.context.thread_uuid, "\0");
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
        if (init_select(&cli, &fds) == -1)
            return (84);
        if (FD_ISSET(STDIN_FILENO, &fds))
            send_message(&cli);
        else if (FD_ISSET(cli.sockfd, &fds))
            rcv = receive_message(&cli);
        if (rcv == 0)
            break;
    }
    return (0);
}
