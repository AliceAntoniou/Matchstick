/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** can_I_win
*/

#include "criterion/criterion.h"
#include "matchstick.h"

int can_I_win(main_t *main, int *matches);

Test(Test_1, can_I_win)
{
    main_t main;
    int matches[4] = {0, 0, 0, 0};

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(can_I_win(&main, matches), -1);
}

Test(Test_2, can_I_win)
{
    main_t main;
    int matches[4] = {1, 3, 5, 7};

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(can_I_win(&main, matches), -1);
}

Test(Test_3, can_I_win)
{
    main_t main;
    int matches[4] = {0, 3, 5, 0};

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(can_I_win(&main, matches), -1);
}

Test(Test_4, can_I_win)
{
    main_t main;
    int matches[4] = {0, 3, 0, 0};

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(can_I_win(&main, matches), 2);
}