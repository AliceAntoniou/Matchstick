/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** game
*/

#include "matchstick.h"
#include <stdlib.h>
#include <time.h>

void remove_matches(main_t *main)
{
    for (size_t i = main->line_nbr * 2; main->matches > 0 && i > 0; i--) {
        if (main->map[main->line][i] == '|') {
            main->map[main->line][i] = ' ';
            main->matches--;
        }
    }
}

int check_win(char **map)
{
    for (size_t j = 1; map[j]; j++)
        for (size_t i = 1; map[j][i]; i++)
            if (map[j][i] == '|')
                return 0;
    return 1;
}

int game(main_t *main)
{
    srandom(time(NULL));

    while (1) {
        print_map(main->map);
        if (check_win(main->map))
            return 1;
        if (!get_param(main))
            return 0;
        my_printf("Player removed %d match(es) from line %d\n", \
                                main->matches, main->line);
        remove_matches(main);
        print_map(main->map);
        if (check_win(main->map))
            return 2;
        ai_param(main);
        my_printf("AI removed %d match(es) from line %d\n", \
                                main->matches, main->line);
        remove_matches(main);
    }
    return 0;
}