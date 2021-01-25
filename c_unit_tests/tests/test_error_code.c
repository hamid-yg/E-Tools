/*
** EPITECH PROJECT, 2021
** test_error_code
** File description:
** test_error_code
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

int error(void)
{
    write(2, "error", 5);
    exit(0);
}

Test(error, exit_code, .exit_code=0)
{
    error();
    cr_assert_stderr_eq_str("error");
}