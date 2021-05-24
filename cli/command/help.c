/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** help
*/

#include "cli.h"

int command_help(char **argv, request_t *msg, cli_t *cli)
{
    FILE *file;
    char c;

    (void)(argv);
    (void)(msg);
    (void)(cli);
    file = fopen(PATH_COMMAND_HELP, "r");
    if (file == NULL) {
        printf("Error: %s is missing\n", PATH_COMMAND_HELP);
        return (0);
    }
    c = fgetc(file);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(file);
    }
    printf("\n");
    fclose(file);
    return (0);
}