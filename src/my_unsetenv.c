/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** unsetenv
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

char *remove_equal(char *buffer)
{
    int i = 0;
    int j = 0;
    char *str = NULL;

    if ((str = malloc(sizeof(char) * my_strlen(buffer))) == NULL)
        return (NULL);
    for (;buffer[j] != '='; i++, j++)
        str[i] = buffer[j];
    str[i] = '\0';
    return (str);
}

char **recreate_env_without(char **env, int del_val,  myenv_t *c)
{
    int count = 0;
    int i = 0;
    int j = 0;

    for (; env[count] != NULL; count++);
    if ((c->env = malloc(sizeof(char *) * (count))) == NULL)
        return NULL;
    c->size = count;
    for (; j != count; j++)
        if (j != del_val) {
            c->env[i] = line_cpy(env[j]);
            i++;
        }
    c->env[count] = NULL;
    return (c->env);
}

char **env_del(char **env, char *buff)
{
    myenv_t *c = malloc(sizeof(myenv_t));
    char *str = NULL;

    for (int count = 0; env[count] != NULL; count++) {
            str = remove_equal(env[count]);
            if (my_strcmp(buff, str) == 0) {
                c->env = recreate_env_without(env, count, c);
                return (c->env);
            }
    }
    return NULL;
}

int undo_elem(myenv_t *cpy, char **av, int ac)
{
    int count = 1;

    if (ac == 2) {
        for (; count != ac; count++)
            if (env_del(cpy->env, buff_cpy(av[count])) != NULL)
                cpy->env = env_del(cpy->env, buff_cpy(av[count]));
    } else {
        for (; count != ac - 1; count++) {
            if (env_del(cpy->env, av[count]) != NULL)
                cpy->env = env_del(cpy->env, av[count]);
        }
        if (env_del(cpy->env, buff_cpy(av[count])) != NULL)
            cpy->env = env_del(cpy->env, buff_cpy(av[count]));
    }
}

int my_unsetenv(char *buffer, myenv_t *cpy)
{
    char **array = my_str_to_word_array(buffer, " ");
    int ac = 0;

    if (my_strcmp(array[0], "unsetenv") == 0) {
        for (; array[ac] != NULL; ac++);
        if (ac < 2) {
            my_put_error("unsetenv: Too few arguments.\n");
            return 0;
        }
        undo_elem(cpy, array, ac);
        return 0;
    }
    return 1;
}
