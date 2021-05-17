/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** exit builtin
*/

#include <stdlib.h>
#include "my.h"

int my_exit(char *buffer)
{
    if (my_strcmp(buffer, "exit\n") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    return (1);
}
