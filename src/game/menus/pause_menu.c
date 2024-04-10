/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Pause menu
*/

#include "my_rpg.h"

void pause_menu_display(main_t *main)
{
    sfRenderWindow_drawSprite(main->window->screen,
    main->pause_menu->background, NULL);
    sfRenderWindow_drawRectangleShape(main->window->screen,
    main->pause_menu->layer, NULL);
}
