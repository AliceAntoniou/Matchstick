/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** ia
*/

#include "matchstick.h"
#include <stdlib.h>

int is_enough_matches(main_t *main)
{
    int count = main->matches;

    for (size_t i = 0; main->map[main->line][i]; i++)
        if (main->map[main->line][i] == '|')
            count--;
    if (count > 0)
        return 0;
    return 1;
}

int *get_matches(main_t *main)
{
    int *matches = malloc(sizeof(int) * (main->line_nbr + 1));

    for (int j = 1; j < main->line_nbr + 1; j++)
        for (int i = 1; main->map[j][i]; i++)
            if (main->map[j][i] == '|')
                matches[j - 1]++;
    return matches;
}

void ai_param(main_t *main)
{
    int *matches = get_matches(main);

    my_putstr("\nAI's turn...\n");
    main->matches = 1;
    main->line = can_i_win(main, matches);
    if (main->line == -1) {
        do {
            main->line = 1 + random() % main->line_nbr;
        } while (!is_enough_matches(main));
        do {
            main->matches = 1 + random() % main->max_out;
            if (matches[main->line - 1] > 2 && \
                main->matches > matches[main->line - 1] - 2)
                main->matches = matches[main->line - 1] - 2;
        } while (!is_enough_matches(main));
    }
}