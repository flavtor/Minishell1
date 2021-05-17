/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** %p
*/

#include "my.h"

int pointer_adress(unsigned long nb)
{
    my_putstr("0x");
    convert_hex_lowercase(nb);
}
