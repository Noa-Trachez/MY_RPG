/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** NPCs display
*/

#include "my_rpg.h"

void npc_display(npc_t *npc, window_t *window, int current_map)
{
    npc_t *save = npc;
    int selector;

    for (int i = 0 ; save; save = save->next, i++) {
        if (save->map != current_map)
            continue;
        sfRenderWindow_drawRectangleShape(window->screen,
        save->sprite, 0);
        selector = save->selector;
        if (save->isSelected == 1) {
            sfRenderWindow_setView(window->screen, window->menuView);
            sfText_setString(save->text, DISCUSS[i][selector][save->index]);
            resize_npc(window, save);
            sfRenderWindow_setView(window->screen, window->gameView);
        }
    }
}
