/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** save
*/

#include "server.h"

int save_data(const char *path, server_t *server)
{
    // printf("here\n");
    FILE *file = fopen(path, "w");

    if (file == NULL) {
        printf("Path: %s\n", path);
        printf("[save_data] Open fail\n");
        return -1;
    }
    fwrite(server, sizeof(server_t), 1, file);
    fclose(file);
    return 0;
}

void load_data(const char *path, server_t *server)
{
    FILE *file = fopen(path, "r");

    if (file == NULL)
        return;
    fread(server, sizeof(server_t), 1, file);
    fclose(file);
    return;
}