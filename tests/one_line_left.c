/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** one_line_left
*/

#include "criterion/criterion.h"
#include "matchstick.h"

int one_line_left(main_t *main, int *matches, int line_1, int);

Test(Test_1, one_line_left)
{
    main_t main;
    int matches[4] = {0, 1, 0, 0};
    int line_1 = 1;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(one_line_left(&main, matches, line_1, 0), 2);
}

Test(Test_2, one_line_left)
{
    main_t main;
    int matches[4] = {0, 2, 0, 0};
    int line_1 = 1;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(one_line_left(&main, matches, line_1, 0), 2);
}

Test(Test_3, one_line_left)
{
    main_t main;
    int matches[4] = {0, 4, 0, 0};
    int line_1 = 1;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(one_line_left(&main, matches, line_1, 0), 2);
}

Test(Test_4, one_line_left)
{
    main_t main;
    int matches[4] = {0, 0, 0, 7};
    int line_1 = 3;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(one_line_left(&main, matches, line_1, 0), 4);
    cr_assert_eq(main.matches, 2);
}

Test(Test_5, one_line_left)
{
    main_t main;
    int matches[5] = {0, 0, 0, 0, 9};
    int line_1 = 4;

    main.line_nbr = 5;
    main.max_out = 3;
    cr_assert_eq(one_line_left(&main, matches, line_1, 0), -1);
}

Test(Test_6, one_line_left)
{
    main_t main;
    int matches[4] = {0, 0, 0, 5};
    int line_1 = 3;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(one_line_left(&main, matches, line_1, 0), -1);
}