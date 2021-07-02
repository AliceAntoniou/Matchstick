/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** get_matches
*/

#include "criterion/criterion.h"
#include "matchstick.h"

int *get_matches(main_t *main);

Test(Test_1, get_matches)
{
    main_t main;
    int *matches;

    main.map[0] = "*******\n";
    main.map[1] = "*  |  *\n";
    main.map[2] = "* ||| *\n";
    main.map[3] = "*|||||*\n";
    main.map[4] = "*******\n";
    main.map[5] = NULL;
    main.line_nbr = 3;
    main.max_out = 3;
    matches = get_matches(&main);
    cr_assert_eq(matches[0], 1);
    cr_assert_eq(matches[1], 3);
    cr_assert_eq(matches[2], 5);
}