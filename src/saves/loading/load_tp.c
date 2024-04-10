/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TPs loading from save
*/

#include "my_rpg.h"

static int is_last_tp(tp_t *tp)
{
    if (!tp->rect.left && !tp->rect.top &&
        !tp->rect.width && !tp->rect.height)
        return (1);
    return (0);
}

void load_tp(game_t *game, int fd)
{
    tp_t **tp = game->tp;

    for (int i = 0; is_last_tp(tp[i]); i++)
        read(fd, &tp[i]->activate, sizeof(int));
}
