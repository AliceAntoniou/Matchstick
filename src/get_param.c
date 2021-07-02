/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** get_param
*/

#include "matchstick.h"
#include <stdio.h>
#include <stdlib.h>

static int get_line(main_t *main)
{
    char *tmp = NULL;
    size_t n = 0;

    my_putstr("Line: ");
    getline(&tmp, &n, stdin);
    for (size_t i = 0; tmp[i]; i++)
        if (my_is_in_str(tmp[i], "0123456789\n") == -1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            free(tmp);
            return 0;
        }
    if (tmp[0] == '\n')
        return 0;
    if (tmp[0] == '\0')
        return -1;
    main->line = my_getnbr(tmp);
    free(tmp);
    if (main->line <= 0 || main->line > main->line_nbr)
        return (my_putstr("Error: this line is out of range\n") * 0);
    return 1;
}

static int test_match_arg(main_t *main)
{
    if (main->matches <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return 0;
    }
    if (main->matches > main->max_out) {
        my_printf("Error: you cannot remove more than %d matches per turn\n", \
                                                main->max_out);
        return 0;
    }
    if (!is_enough_matches(main)) {
        my_putstr("Error: not enough matches on this line\n");
        return 0;
    }
    return 1;
}

static int get_matches(main_t *main)
{
    char *tmp = NULL;
    size_t n = 0;

    my_putstr("Matches: ");
    getline(&tmp, &n, stdin);
    for (size_t i = 0; tmp[i]; i++)
        if (my_is_in_str(tmp[i], "0123456789\n") == -1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            free(tmp);
            return 0;
        }
    if (tmp[0] == '\n')
        return 0;
    if (tmp[0] == '\0')
        return -1;
    main->matches = my_getnbr(tmp);
    free(tmp);
    return test_match_arg(main);
}

int get_param(main_t *main)
{
    int test = 0;

    my_putstr("\nYour turn:\n");
    while (test == 0 || test == 1) {
        main->line = 0;
        main->matches = 1;
        test = 0;
        test = get_line(main);
        if (test == 1)
            test = get_matches(main) + 1;
    }
    if (test == -1)
        return 0;
    return 1;
}
