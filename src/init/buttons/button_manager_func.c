/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** INIY Buttons
*/

#include "my_rpg.h"

void exit_function(main_t *main)
{
    sfRenderWindow_close(main->window->screen);
}

void build_pause_button(main_t *main)
{
    build_button(&main->buttons, "srpf", PAUSE_MENU,
    BUTTON_SPRITE[CONTINUE_BUTTON], (sfVector2f){main->window->mode.width / 2,
    main->window->mode.height / 4.2}, &return_to_game);
    build_button(&main->buttons, "srpf", PAUSE_MENU,
    BUTTON_SPRITE[SETTINGS_BUTTON], (sfVector2f){main->window->mode.width / 2,
    main->window->mode.height / 2}, &goto_settings);
    build_button(&main->buttons, "srpf", PAUSE_MENU,
    BUTTON_SPRITE[EXIT_BUTTON], (sfVector2f){main->window->mode.width / 2,
    main->window->mode.height / 1.3}, &goto_menu);
}
