/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** init_tp
*/

#include "my_rpg.h"

void init_tp(main_t *main)
{
    for (int i = 0; ALL_TP[i].activate != END; i++) {
        main->game->tp[i] = malloc(sizeof(tp_t));
        main->game->tp[i]->activate = ALL_TP[i].activate;
        main->game->tp[i]->actual = ALL_TP[i].actual;
        main->game->tp[i]->go_to = ALL_TP[i].go_to;
        main->game->tp[i]->rect = ALL_TP[i].rect;
        main->game->tp[i]->spawn = ALL_TP[i].spawn;
    }
}
