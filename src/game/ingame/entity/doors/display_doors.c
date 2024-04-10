/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Display doors
*/

#include "my_rpg.h"

void doors_display(main_t *main)
{
    door_t *save = main->game->doors;

    while (save) {
        if (save->map != main->game->map->currentMap) {
            save = save->next;
            continue;
        }
        sfRenderWindow_drawRectangleShape(main->window->screen,
        save->first, 0);
        if (save->second)
            sfRenderWindow_drawRectangleShape(main->window->screen,
            save->second, 0);
        save = save->next;
    }
}
