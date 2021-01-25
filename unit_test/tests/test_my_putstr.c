/*
** EPITECH PROJECT, 2021
** test_my_putstr
** File description:
** test_my_putstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_putstr(const char *str);

void redirect_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(putstr, test_my_putstr, .init=redirect_stdout)
{
    my_putstr("hello");
    cr_assert_stdout_eq_str("hello");
}