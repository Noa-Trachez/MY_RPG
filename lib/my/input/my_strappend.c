/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender-noa.trachez
** File description:
** my_strappend.c
*/

#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (; src[i]; i++)
        dest[i] = src[i];
    return (dest);
}

static char *my_strcat(char *dest, char const *src)
{
    my_strcpy(dest + my_strlen(dest), src);
    return (dest);
}

char *my_strappend(char *str, char *fill, int free_str)
{
    int len = my_strlen(str) + my_strlen(fill);
    char *new = malloc(len + 1);

    memset(new, 0, len + 1);
    my_strcpy(new, str);
    my_strcat(new, fill);
    if (free_str)
        free(str);
    return (new);
}
