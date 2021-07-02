/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** main matchstick
*/

#include "matchstick.h"

void print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("    matchstick l m\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    l    number of lines (0 < l < 100)\n");
    my_putstr("    m    maximum number of matches that can be taken \
                outeach turn (0 < m)\n");
}

int parse_args(int ac, char const *av[], main_t *main)
{
    if (ac == 2 && my_str_is_identical(av[1], "-h")) {
        print_usage();
        return 0;
    }
    if (ac != 3) {
        print_usage();
        return 84;
    }
    main->line_nbr = my_getnbr(av[1]);
    main->max_out = my_getnbr(av[2]);
    if (main->line_nbr <= 0 || main->line_nbr >= 100 || main->max_out <= 0) {
        my_putstr("Invalide arguments\n");
        return 84;
    }
    return 1;
}

int matchstick(int ac, char const *av[])
{
    main_t main;
    int check = 0;

    if ((check = parse_args(ac, av, &main)) != 1)
        return check;
    init_map(&main);
    switch (game(&main)) {
    case 1:
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return 1;
    case 2:
        my_putstr("You lost, too bad...\n");
        return 2;
    }
    return 0;
}