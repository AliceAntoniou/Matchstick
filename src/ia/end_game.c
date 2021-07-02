/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** end_game
*/

#include "matchstick.h"

int one_line_left(main_t *main, int *matches, int line_1, int bool)
{
    if (matches[line_1] - (1 + bool) > main->max_out) {
        if (matches[line_1] == main->max_out + (2 + bool) || \
            matches[line_1] - main->max_out - (2 + bool) > main->max_out)
            return -1;
        main->matches = matches[line_1] - main->max_out - (2 + bool);
        return (line_1 + 1);
    }
    main->matches = matches[line_1] - 1;
    if (main->matches == 0)
        main->matches = 1;
    return (line_1 + 1);
}

int two_plus_per_line(main_t *main, int *matches, int line_1, int line_2)
{
    if (matches[line_1] == 2) {
        if (matches[line_2] <= 2 || matches[line_2] > main->max_out + 2)
            return one_line_left(main, matches, line_2, 1);
        main->matches = matches[line_2] - 2;
        return (line_2 + 1);
    }
    if (matches[line_2] == 2) {
        if (matches[line_1] <= 2 || matches[line_1] > main->max_out + 2)
            return one_line_left(main, matches, line_1, 1);
        main->matches = matches[line_1] - 2;
        return (line_1 + 1);
    }
    return -1;
}

int two_lines_left(main_t *main, int *matches, int line_1, int line_2)
{
    if (matches[line_1] == 1) {
        if (matches[line_2] > main->max_out)
            return -1;
        main->matches = matches[line_2];
        return (line_2 + 1);
    }
    if (matches[line_2] == 1) {
        if (matches[line_1] > main->max_out)
            return -1;
        main->matches = matches[line_1];
        return (line_1 + 1);
    }
    return two_plus_per_line(main, matches, line_1, line_2);
}

int can_i_win(main_t *main, int *matches)
{
    int count = 0;
    int line_1 = -1;
    int line_2 = -1;

    for (int i = 0; i < main->line_nbr; i++) {
        if (matches[i] > 0) {
            count++;
            if (line_1 == -1)
                line_1 = i;
            else if (line_2 == -1)
                line_2 = i;
        }
    }
    if (count == 2)
        return two_lines_left(main, matches, line_1, line_2);
    if (count == 1)
        return one_line_left(main, matches, line_1, 0);
    return -1;
}