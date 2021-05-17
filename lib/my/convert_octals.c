/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** %o
*/

#include "my.h"

int convert_octals(int nb)
{
    int leftovers = 0;

    for (int reverse = 1; nb != 0; reverse *= 10) {
        leftovers += (nb % 8) * reverse;
        nb /= 8;
    }
    my_put_nbr(leftovers);
    return (leftovers);
}
