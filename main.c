/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** main function
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "minishell.h"

char *line_cpy(char *env_i)
{
    char *line = malloc(sizeof(char) + (my_strlen(env_i) + 1));
    int count = 0;

    for (; count != my_strlen(env_i); count++)
        line[count] = env_i[count];
    line[count] = '\0';
    return (line);
}

myenv_t *env_cpy(char **env)
{
    myenv_t *c = malloc(sizeof(myenv_t));
    int count = 0;
    int i = 0;

    for (; env[count] != NULL; count++);
    if ((c->env = malloc(sizeof(char *) * (count + 1))) == NULL)
        return NULL;
    c->size = count;
    for (; i != count; i++)
        c->env[i] = line_cpy(env[i]);
    c->env[count] = NULL;
    return (c);
}

int main(int ac, char **av, char **env)
{
    myenv_t *cpy = env_cpy(env);

    return (minishell(ac, av, cpy));
}
