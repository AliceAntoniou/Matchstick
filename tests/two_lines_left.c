/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** two_lines_left
*/

#include "criterion/criterion.h"
#include "matchstick.h"

int two_lines_left(main_t *main, int *matches, int line_1, int line_2);

Test(Test_1, two_lines_left)
{
    main_t main;
    int matches[4] = {0, 1, 2, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(two_lines_left(&main, matches, line_1, line_2), 3);
}

Test(Test_2, two_lines_left)
{
    main_t main;
    int matches[4] = {0, 2, 1, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(two_lines_left(&main, matches, line_1, line_2), 2);
}

Test(Test_3, two_lines_left)
{
    main_t main;
    int matches[4] = {0, 5, 1, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(two_lines_left(&main, matches, line_1, line_2), -1);
}

Test(Test_4, two_lines_left)
{
    main_t main;
    int matches[4] = {0, 1, 5, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(two_lines_left(&main, matches, line_1, line_2), -1);
}

Test(Test_5, two_lines_left)
{
    main_t main;
    int matches[4] = {0, 3, 3, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(two_lines_left(&main, matches, line_1, line_2), -1);
}