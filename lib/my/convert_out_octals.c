/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** convert non printable char to octals in a string
*/

#include "my.h"

void convert_out_octals(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 31 && str[i] < 127) {
            my_putchar(str[i]);
        } else {
            convert_octals(str[i]);
            my_put_nbr(str[i]);
        }
    }
}
