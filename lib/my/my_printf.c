/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print differents types of variables
*/

#include <stdarg.h>
#include <stddef.h>
#include "my.h"

void flags_gestion(const char *format, int i, va_list ap)
{
    switch (format[i + 1]) {
    case 's':
        my_putstr(va_arg(ap, char*));
        break;
    case 'c':
    case 'C':
        my_putchar((char) va_arg(ap, int));
        break;
    case 'd':
    case 'i':
        my_put_nbr(va_arg(ap, int));
        break;
    case 'u':
        my_put_nbr_pos(va_arg(ap, unsigned long));
        break;
    case 'p':
        pointer_adress(va_arg(ap, unsigned long));
        break;
    }
}

void convert_gestion(const char *format, int i, va_list ap)
{
    switch (format[i + 1]) {
    case 'b':
        convert_binary(va_arg(ap, int));
        break;
    case 'o':
        convert_octals(va_arg(ap, int));
        break;
    case 'x':
        convert_hex_lowercase(va_arg(ap, unsigned long));
        break;
    case 'X':
        convert_hex_uppercase(va_arg(ap, unsigned long));
        break;
    case 'S':
        convert_out_octals(va_arg(ap, char*));
        break;
    }
}

int last_flags_gestion(const char *format, int i, va_list ap)
{
    switch (format[i + 1]) {
    case 'm':
        my_putstr("Success");
        break;
    case 'l':
        flags_gestion(format, i + 1, ap);
        convert_gestion(format, i + 1, ap);
        return (i + 1);
    }
    return (i);
}

int my_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, *format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            flags_gestion(format, i, ap);
            convert_gestion(format, i, ap);
            i = last_flags_gestion(format, i, ap);
            i++;
        } else
            my_putchar(format[i]);
    }
    va_end(ap);
}
