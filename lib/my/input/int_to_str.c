/*
** EPITECH PROJECT, 2021
** B-PSU-100-LIL-1-1-myprintf-noa.trachez
** File description:
** int_to_str.c
*/

#include <string.h>
#include "../include/my.h"
#include <stdlib.h>

static int my_nbrlen(unsigned long nb)
{
    int len = 0;

    for (; nb > 0; len++)
        nb /= 10;
    return (len);
}

int my_strlen(char const *str)
{
    int len = 0;

    for (len = 0; str[len] != '\0'; len++);
    return (len);
}

static char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int tmp_len = len - 1;
    char tmp;

    for (int i = 0; i < (len / 2); i++, tmp_len--) {
        tmp = str[i];
        str[i] = str[tmp_len];
        str[tmp_len] = tmp;
    }
    str[len] = '\0';
    return (str);
}

char *int_to_str(unsigned long nb)
{
    int len = my_nbrlen(nb);
    int tmp_len;
    char *str;

    (nb == 0) ? len++ : 0;
    tmp_len = len;
    str = malloc(len + 1);
    for (int i = 0; tmp_len > 0; i++, tmp_len--, nb /= 10)
        str[i] = nb % 10 + 48;
    str[len] = '\0';
    my_revstr(str);
    return (str);
}
