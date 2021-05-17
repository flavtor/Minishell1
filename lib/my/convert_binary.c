/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** convert to binary
*/

#include "my.h"

int print_last_zero(int value, int nb)
{
    my_putchar('1');
    nb /= 2;
    while (nb != 0) {
        nb /= 2;
        my_putchar('0');
    }
    return (nb);
}

int convert_binary(int nb)
{
    int place_value = 0;
    int units_place = 1;

    for (; units_place <= nb; units_place *= 2);
    place_value = units_place / 2;
    while (nb != 0) {
        if (nb > place_value) {
            nb -= place_value;
            place_value /= 2;
            my_putchar('1');
        } else if (nb == place_value)
            nb = print_last_zero(place_value, nb);
        else {
            place_value /= 2;
            my_putchar('0');
        }
    }
}
