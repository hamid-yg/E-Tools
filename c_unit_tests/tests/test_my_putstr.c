/*
** EPITECH PROJECT, 2021
** test_my_putstr
** File description:
** test_my_putstr
*/

#include "test_redirect.h"

void my_putstr(const char *str);

Test(putstr, test_my_putstr, .init=redirect_stdout)
{
    my_putstr("hello");
    cr_assert_stdout_eq_str("hello");
}