/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** test_strtwa
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "cli.h"
#include "communication.h"

Test(str_to_word_array, str_to_word_array_test)
{
    char *str = strdup("/login \"toto\" \"titi\"");
    char **tab = NULL;
    int len = 0;

    tab = str_to_word_array(str, " \n", &len);
    cr_assert_eq(len, 3);
    free_world_arr(tab, len);
}