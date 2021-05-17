/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** put positive number
*/

#include "my.h"

int my_put_nbr_pos(unsigned long number)
{
    int tmp = 0;

    if (number >= 10) {
        tmp = number % 10;
        number = (number - tmp) / 10;
        modulo_gestion(number);
        my_putchar(tmp + '0');
    } else if (number < 10)
        my_putchar(number + '0');
    return (0);
}
