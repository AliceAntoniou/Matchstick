/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** map
*/

#include "matchstick.h"
#include <stdlib.h>

void print_map(char **map)
{
    while (*map) {
        my_putstr(*map);
        map++;
    }
}

static void make_star_lines(main_t *main)
{
    main->map[0] = malloc(sizeof(char) * main->line_nbr * 2 + 3);
    for (int i = 0; i < main->line_nbr * 2 + 1; i++)
        main->map[0][i] = '*';
    main->map[0][main->line_nbr * 2 + 1] = '\n';
    main->map[0][main->line_nbr * 2 + 2] = '\0';
    main->map[main->line_nbr + 1] = malloc(sizeof(char) * \
                                    main->line_nbr * 2 + 3);
    for (int i = 0; i < main->line_nbr * 2 + 1; i++)
        main->map[main->line_nbr + 1][i] = '*';
    main->map[main->line_nbr + 1][main->line_nbr * 2 + 1] = '\n';
    main->map[main->line_nbr + 1][main->line_nbr * 2 + 2] = '\0';
}

void init_map(main_t *main)
{
    main->map = malloc(sizeof(char *) * (main->line_nbr + 3));
    make_star_lines(main);
    for (int i = 1; i < main->line_nbr + 1; i++) {
        main->map[i] = malloc(sizeof(char) * main->line_nbr * 2 + 3);
        main->map[i][0] = '*';
        for (int j = 1; j < main->line_nbr * 2; j++) {
            if (j >= main->line_nbr - (i - 1) && j <= main->line_nbr + (i - 1))
                main->map[i][j] = '|';
            else
                main->map[i][j] = ' ';
        }
        main->map[i][main->line_nbr * 2] = '*';
        main->map[i][main->line_nbr * 2 + 1] = '\n';
        main->map[i][main->line_nbr * 2 + 2] = '\0';
    }
    main->map[main->line_nbr + 2] = NULL;
}