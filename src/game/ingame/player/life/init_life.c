/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** init_life
*/

#include "my_rpg.h"

void init_life(main_t *main)
{
    hud_t *hud = main->hud;

    for (int i = 0; i < 2; i++) {
        hud->life[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(hud->life[i], (sfVector2f){200, 30});
        sfRectangleShape_setPosition(hud->life[i], (sfVector2f){50, 1010});
    }
    sfRectangleShape_setFillColor(hud->life[0], (sfColor){120, 120, 120, 120});
    sfRectangleShape_setFillColor(hud->life[1], sfGreen);
    sfRectangleShape_setOutlineColor(hud->life[0], sfWhite);
    sfRectangleShape_setOutlineThickness(hud->life[0], 2);
}
