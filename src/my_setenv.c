/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** setenv
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "minishell.h"

int error_setenv(char **av)
{
    if ((av[1][0] < 'a' || av[1][0] > 'z')
        && (av[1][0] < 'A' || av[1][0] > 'Z')) {
        my_put_error("setenv: Variable name must begin with a letter.\n");
        return (84);
    }
    return (0);
}

char **env_add(char **env, char **av)
{
    myenv_t *c = malloc(sizeof(myenv_t));
    int count = -1;
    int i = 0;
    char *str = NULL;

    if (error_setenv(av) == 84)
        return NULL;
    if (av[2]) {
        str = my_strcat(av[1], "=");
        str = my_strcat(str, buff_cpy(av[2]));
    } else
        str = my_strcat(buff_cpy(av[1]), "=");
    for (; env[count] != NULL; count++);
    if ((c->env = malloc(sizeof(char *) * (count + 1))) == NULL)
        return NULL;
    c->size = count;
    for (; i != count; i++)
        c->env[i] = line_cpy(env[i]);
    c->env[i] = str;
    c->env[i + 1] = NULL;
    return (c->env);
}

myenv_t *add_elem_env(myenv_t *cpy, char **av)
{
    if (env_add(cpy->env, av) != NULL)
        cpy->env = env_add(cpy->env, av);
}

int my_setenv(char *buffer, myenv_t *cpy)
{
    char **array = my_str_to_word_array(buffer, " ");
    int ac = 0;

    if (my_strcmp(array[0], "setenv") == 0) {
        for (; array[ac] != NULL; ac++);
        if (ac < 2) {
            my_put_error("setenv: Too few arguments.\n");
            return 0;
        } else if (ac > 3) {
            my_put_error("setenv: Too many arguments.\n");
            return 0;
        }
        cpy = add_elem_env(cpy, array);
        return 0;
    }
    return 1;
}
