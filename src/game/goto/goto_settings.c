/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Goto settings menu
*/

#include "my_rpg.h"

void goto_settings(main_t *main)
{
    main->scene = SETTINGS_MENU;
    sfText_setPosition(main->menu->msg, (sfVector2f){main->window->mode.width
    / 2.25, main->window->mode.height / 1.7});
}
