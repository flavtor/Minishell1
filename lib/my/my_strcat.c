/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *de, char *src)
{
    int i = 0;
    char *str = malloc(sizeof(char) * ((my_strlen(de) + (my_strlen(src) + 1))));

    for (i; de[i] != '\0'; i++)
        str[i] = de[i];
    for (int count = 0; src[count] != '\0'; count++) {
        str[i] = src[count];
        i++;
    }
    str[i] = '\0';
    return (str);
}
