/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my_exec
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include "my.h"

void print_process_segfault(int wstatus)
{
    if (WTERMSIG(wstatus) == 11)
        my_printf("Segmentation fault\n");
    if (WTERMSIG(wstatus) == 8)
        my_printf("Floating exception\n");
}

char *buff_cpy(char *buffer)
{
    int i = 0;
    int j = 0;
    char *str = NULL;

    if ((str = malloc(sizeof(char) * my_strlen(buffer))) == NULL)
        return (NULL);
    for (; buffer[j] != '\n'; i++, j++)
        str[i] = buffer[j];
    str[i] = '\0';
    return (str);
}

int my_exec(char *buff, char **env)
{
    char *str = buff_cpy(buff);
    char **array = my_str_to_word_array(str, " ");
    int i = 0;
    int pid = getpid();
    int wstatus;

    if ((pid = fork()) == -1)
        return (84);
    if (pid != 0) {
        if (waitpid(pid, &wstatus, 0) == -1)
            return (84);
        if (WIFSIGNALED(wstatus) == 1) {
            print_process_segfault(wstatus);
            return (84);
        }
        return (0);
    }
    else
        if (execve(array[0], array, env) == -1)
            return (84);
}
