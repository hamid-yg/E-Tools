/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** display a char*
*/

#include <unistd.h>

void my_putstr(const char *str)
{
    for (int i = 0; str[i]; i++)
        write(1, &str[i], 1);
}