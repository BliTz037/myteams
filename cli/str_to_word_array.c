/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** str_to_word_array
*/

#include "cli.h"
#include "communication.h"

void free_world_arr(char **tab, const int len)
{
    for (int i = 0; i < len; i++)
        if (tab[i] != NULL)
            free(tab[i]);
    free(tab);
}

char **str_to_word_array(char *str, const char *delim, int *len)
{
    char **tab = malloc(sizeof(char *));
    char *token = strtok(str, delim);
    int i = 0;

    if (!str || !token || !delim)
        return NULL;
    while (token != NULL) {
        if (strcmp(token, " ") != 0) {
            tab[i] = strdup(token);
            i++;
            tab = realloc(tab, (sizeof(char *) * (i + 1)));
        }
        token = strtok(NULL, "\"\n");
    }
    tab[i] = NULL;
    *len = i;
    return tab;
}