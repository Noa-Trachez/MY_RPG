/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Game loop with scene redirection
*/

#include "my_rpg.h"

void game_loop(main_t *main)
{
    void (*scene[])(main_t *) = {&main_menu_display, &how_to_play_manager,
    &load_menu, &binding_menu, &pause_menu_display,
    &ingame_loop, &settings_menu_display};

    scene[main->scene](main);
    button_display(main->window, main->buttons, main->scene);
}
