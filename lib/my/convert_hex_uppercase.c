/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** convert to hex up
*/

#include "my.h"

void print_hex_up(unsigned long nb)
{
    if (nb < 10)
        my_putchar(nb + '0');
    if (nb >= 10 && nb <= 15)
        my_putchar(nb % 10 + 'A');
}

void convert_hex_uppercase(unsigned long nb)
{
    long hex = 1;

    while (hex <= nb)
        hex *= 16;
    hex /= 16;
    while (nb >= 16) {
        print_hex_up(nb / hex);
        nb %= hex;
        hex /= 16;
    }
    print_hex_up(nb);
}
