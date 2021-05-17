/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** cd
*/

#include <unistd.h>
#include "my.h"

int my_cd(char *buffer)
{
    char *str = buff_cpy(buffer);
    char **array = my_str_to_word_array(str, " ");
    int ac = 0;

    if (my_strcmp(array[0], "cd") == 0) {
        for (; array[ac] != NULL; ac++);
        if (ac > 2) {
            my_put_error("cd: Too many arguments.\n");
            return (0);
        } else if (ac == 1) {
            chdir("/home/luca");
        } else {
            if (chdir(array[1]) == -1) {
                my_put_error(array[1]);
                my_put_error(": Not a directory.\n");
                return (84);
            } else
                return (0);
        }
    }
    return (1);
}
