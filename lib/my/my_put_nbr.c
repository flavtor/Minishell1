/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display number given as parameter
*/

#include "my.h"

int modulo_gestion(long number)
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

int my_put_nbr(int nb)
{
    long number = nb;

    if (nb < 0) {
        my_putchar('-');
        number = number * -1;
        modulo_gestion(number);
    } else
        modulo_gestion(number);
    return (0);
}
