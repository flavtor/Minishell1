/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** env builtin
*/

#include "my.h"

int my_env(char *buffer, char **env)
{
    if (my_strcmp(buffer, "env\n") == 0) {
        for (int i = 0; env[i]; i++)
            my_printf("%s\n", env[i]);
        return (0);
    }
    return (1);
}
