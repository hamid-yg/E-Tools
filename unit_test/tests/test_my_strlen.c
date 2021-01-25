/*
** EPITECH PROJECT, 2021
** test_my_strlen
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

int my_strlen(const char *str);

void setup(void)
{
    puts("Before");
}

void after(void)
{
    puts("After");
}

Test(my_strlen, test_my_strlen, .init=setup, .fini=after, .description="Test de my_strlen")
{
    char *str = "Hello";

    // cr_expect(strlen(str) == my_strlen(str), "Expected to have a length of 5");
    // cr_expect(strlen("") == 0);
    // cr_assert(my_strlen(str) == strlen("DJGDUHd"));
    cr_assert_eq(my_strlen(str), strlen(str));
    // cr_assert_not(my_strlen(str) != strlen(str));
}

// TEST SIGNAL
// Test(my_strlen, test_segfault_v, .signal=SIGSEGV)
// {
//     int *ptr = NULL;
//     *ptr = 42;
// }