/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** my_strcat
*/

#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

char *my_strconcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);
    for (int i = 0; dest[i] != '\0'; i++, j++)
        res[j] = dest[i];
    for (int k = 0; src[k] != '\0'; k++, j++)
        res[j] = src[k];
    res[j] = '\0';
    return (res);
}
