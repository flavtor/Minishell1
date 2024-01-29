
/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** UNIX command interpreter
*/

#include <pwd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include "my.h"

char *recup_path(char **env)
{
    char *path = NULL;
    int line = 0;
    int i = 4;
    int j = 0;

    for (int count = 0; env[count] != NULL; count++) {
        if (env[count][0] == 'P' && env[count][1] == 'A'
            && env[count][2] == 'T' && env[count][3] == 'H')
            line = count;
    }
    path = malloc(sizeof(char) * my_strlen(env[line]));
    for (int count = 0; env[line][i] != '\0'; count++, i++, j++)
        path[j] = env[line][i];
    path[j] = '\0';
    return (path);
}

char *remove_spc(char *buffer)
{
    int i = 0;
    int j = 0;
    char *str = NULL;

    if ((str = malloc(sizeof(char) * my_strlen(buffer))) == NULL)
        return (NULL);
    for (;buffer[j] != '\n' && buffer[j] != ' '; i++, j++)
        str[i] = buffer[j];
    str[i] = '\0';
    return (str);
}

int cmd_is_access(char *buffer, char **env, char *path)
{
    char **array = my_str_to_word_array(path, ":");
    char *str = NULL;

    if (access(remove_spc(buffer), F_OK) == 0) {
        if (my_exec(buffer, env) == 84)
            return (84);
    } else {
        for (int count = 0; array[count] != NULL; count++) {
            str = my_strcat(array[count], "/");
            str = my_strcat(str, buffer);
            if (access(remove_spc(str), F_OK) == 0)
                if (my_exec(str, env) == 84) {
                    return (84);
                } else
                    return 0;
        }
    }
    my_put_error(buff_cpy(buffer));
    my_put_error(": Command not found.\n");
    return (84);
}

int builtins(char *buffer, myenv_t *cpy)
{
    int count = 0;
    int i = 0;
    char *str = NULL;
    char *path = recup_path(cpy->env);

    count += my_exit(buffer);
    count += my_env(buffer, cpy->env);
    count += my_cd(buffer);
    count += my_setenv(buffer, cpy);
    count += my_unsetenv(buffer, cpy);
    if (count == 5)
        if (cmd_is_access(buffer, cpy->env, path) == 84)
            return (84);
    free(str);
    return (0);
}

int minishell(int ac, char **av, myenv_t *cpy)
{
    DIR *dir = opendir(".");
    size_t size = 200;
    char *cwd = malloc(sizeof(char) * 200);
    char *buffer = NULL;
    int return_val = 0;

    while (1) {
        my_printf("[flavien@localhost %s]$ ", getcwd(cwd, size));
        if (getline(&buffer, &size, stdin) == -1)
            return (0);
        return_val = builtins(buffer, cpy);
    }
    closedir(dir);
    return (return_val);
}
