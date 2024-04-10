/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Settings menu
*/

#include "my_rpg.h"

void settings_menu_display(main_t *main)
{
    sfRenderWindow_drawSprite(main->window->screen,
    main->menu->background, 0);
    sfRenderWindow_drawText(main->window->screen, main->menu->msg, 0);
}
