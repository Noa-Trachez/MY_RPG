/*
** EPITECH PROJECT, 2022
** B-PSU-200-LIL-2-1-mysokoban-william.stoops
** File description:
** my_tabdup
*/

#include <string.h>
#include "../include/my.h"
#include <stdlib.h>

char **my_tabdup(const char **tab)
{
    char **world = NULL;
    int i = 0;
    int j = 0;
    for (; tab[i] != NULL; i++);
    world = malloc(sizeof(char *) * (i + 2));
    for (; tab[j] != NULL; j++)
        world[j] = my_strdup(tab[j]);
    world[j] = NULL;
    return world;
}
