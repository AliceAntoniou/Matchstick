/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include "my_lib.h"

typedef struct main
{
    char **map;
    int line_nbr;
    int max_out;
    int line;
    int matches;
} main_t;

int game(main_t *main);
void init_map(main_t *main);
int get_param(main_t *main);
void print_map(char **map);
void ai_param(main_t *main);
int is_enough_matches(main_t *main);
int can_i_win(main_t *main, int *matches);

#endif /* !MATCHSTICK_H_ */