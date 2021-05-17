/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** my.h
*/

#include <stdarg.h>
#include "minishell.h"

#ifndef MY_H_
#define MY_H_

char *line_cpy(char *env_i);
int my_printf(const char *format, ...);
void my_putchar(char c);
int my_putstr(char const *str);
int modulo_gestion(long number);
int my_put_nbr(int nb);
int my_put_nbr_pos(unsigned long number);
int my_put_error(char const *str);
char *buff_cpy(char *buffer);
int convert_binary(int nb);
int convert_octals(int nb);
void convert_hex_lowercase(unsigned long nb);
void convert_hex_uppercase(unsigned long nb);
int pointer_adress(unsigned long nb);
void convert_out_octals(char *str);
int last_flags_gestion(const char *format, int i, va_list ap);
int minishell(int argc, char **argv, myenv_t *cpy);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *de, char *src);
char **my_str_to_word_array(char const *str, char *delims);
int my_exit(char *buffer);
int my_env(char *buffer, char **env);
int my_exec(char *buff, char **env);
int my_cd(char *buffer);
int my_setenv(char *buffer, myenv_t *cpy);
int my_unsetenv(char *buffer, myenv_t *cpy);

#endif
