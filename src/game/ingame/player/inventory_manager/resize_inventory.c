/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Resize inventory
*/

#include "my_rpg.h"

sfIntRect resize_mouse_slots(window_t *window, sfIntRect rect)
{
    sfIntRect button;

    button = resize_mouse_rect(window, rect);
    return button;
}

void resize_inventory(window_t *window, sfSprite *sprite)
{
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};

    sfSprite_setScale(sprite, (sfVector2f){mode.x, mode.y});
    sfRenderWindow_drawSprite(window->screen, sprite, 0);
}
