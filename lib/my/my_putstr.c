/*
** EPITECH PROJECT, 2019
** putstr
** File description:
** display a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    for (int count = 0; str[count] != '\0'; count++) {
        my_putchar(str[count]);
    }
}
