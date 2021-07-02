/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-damien.antoniou
** File description:
** two_per_line
*/

#include "criterion/criterion.h"
#include "matchstick.h"

int two_plus_per_line(main_t *main, int *matches, int line_1, int line_2);

Test(Test_1, two_per_line)
{
    main_t main;
    int matches[4] = {0, 3, 2, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(two_plus_per_line(&main, matches, line_1, line_2), 2);
}

Test(Test_2, two_per_line)
{
    main_t main;
    int matches[4] = {0, 2, 4, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(two_plus_per_line(&main, matches, line_1, line_2), 3);
}

Test(Test_3, two_per_line)
{
    main_t main;
    int matches[4] = {0, 4, 4, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(two_plus_per_line(&main, matches, line_1, line_2), -1);
}

Test(Test_4, two_per_line)
{
    main_t main;
    int matches[4] = {0, 1, 2, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(two_plus_per_line(&main, matches, line_1, line_2), 2);
}

Test(Test_5, two_per_line)
{
    main_t main;
    int matches[4] = {0, 5, 2, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 2;
    cr_assert_eq(two_plus_per_line(&main, matches, line_1, line_2), -1);
}

Test(Test_6, two_per_line)
{
    main_t main;
    int matches[4] = {0, 2, 1, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 3;
    cr_assert_eq(two_plus_per_line(&main, matches, line_1, line_2), 3);
}

Test(Test_7, two_per_line)
{
    main_t main;
    int matches[4] = {0, 2, 5, 0};
    int line_1 = 1;
    int line_2 = 2;

    main.line_nbr = 4;
    main.max_out = 2;
    cr_assert_eq(two_plus_per_line(&main, matches, line_1, line_2), -1);
}