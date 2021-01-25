/*
** EPITECH PROJECT, 2021
** day02m
** File description:
** test_redirect
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}