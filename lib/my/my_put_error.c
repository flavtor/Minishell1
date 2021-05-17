/*
** EPITECH PROJECT, 2019
** my_put_error
** File description:
** write a message on error output
*/

#include <unistd.h>
#include "my.h"

void my_putchar_error(char c)
{
    write (2, &c, 1);
}

int my_put_error(char const *str)
{
    for (int count = 0; str[count] != '\0'; count++) {
        my_putchar_error(str[count]);
    }
    return (84);
}
