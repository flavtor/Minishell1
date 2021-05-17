/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include <stdlib.h>
#include "my.h"

int my_isad(char c)
{
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
        || ('0' <= c && c <= '9'))
        return (1);
    else
        return (0);
}

int my_isdelim(char *delims, char c)
{
    for (int i = 0; delims[i] != '\0'; i++)
        if (c == delims[i])
            return (1);
    return (0);
}

int count_words(char const *str, char *delims)
{
    int word = 1;
    int j = 0;

    if (str == NULL)
        return (0);
    for (int i = 0; delims[i] != '\0'; i++) {
        for (j = 0; str[j] != '\0'; j++)
            if (str[j] == delims[i] && my_isdelim(delims, str[j + 1]) == 0)
                word++;
    }
    (my_isdelim(delims, str[j - 1]) == 1) ? word-- : word;
    (my_isdelim(delims, str[0]) == 1) ? word-- : word;
    return (word);
}

char **my_str_to_word_array(char const *str, char *delims)
{
    int word = count_words(str, delims);
    char **array = malloc(sizeof(char *) * word + 1);
    int c = 0;
    int i = 0;
    int j = 0;

    if (word == 0)
        return (0);
    for (int count_word = 0; count_word != word; count_word++) {
        for (; my_isdelim(delims, str[i]) == 1; i++);
        for (; my_isdelim(delims, str[i]) == 0 && str[i] != '\0'; i++);
        array[count_word] = malloc(sizeof(char) * i + 1);
    }
    for (int count_word = 0; count_word != word; count_word++) {
        for (; my_isdelim(delims, str[j]) == 1; j++);
        for (c = 0; my_isdelim(delims, str[j]) == 0 && str[j] != '\0'; j++, c++)
            array[count_word][c] = str[j];
        array[count_word][c] = '\0';
    }
    return (array);
}
