/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** convert hexa lowercase
*/

#include "my.h"

void print_hex_low(unsigned long nb)
{
    if (nb < 10)
        my_putchar(nb + '0');
    if (nb >= 10 && nb <= 15)
        my_putchar((nb % 10) + 'a');
}

void convert_hex_lowercase(unsigned long nb)
{
    long hex = 1;

    while (hex <= nb)
        hex *= 16;
    hex /= 16;
    while (nb >= 16) {
        print_hex_low(nb / hex);
        nb %= hex;
        hex /= 16;
    }
    print_hex_low(nb);
}
