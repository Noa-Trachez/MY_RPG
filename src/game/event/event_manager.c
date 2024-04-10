/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Events manager
*/

#include "my_rpg.h"

void event_manager(main_t *main)
{
    void (*scene[])(main_t *) = {&main_menu_event, &how_to_play_event,
    &load_menu_event, &binding_event, &pause_menu_event, &ingame_event,
    &settings_menu_event};

    scene[main->scene](main);
    if (sfKeyboard_isKeyPressed(sfKeyF6))
        save_game(main->game);
    if (main->event.type == sfEvtClosed)
        sfRenderWindow_close(main->window->screen);
    if (main->event.type == sfEvtMouseButtonPressed &&
    main->event.mouseButton.button == sfMouseLeft)
        button_is_pressed(main->buttons, main->window, main->scene);
    if (main->event.type == sfEvtMouseButtonReleased &&
    main->event.mouseButton.button == sfMouseLeft)
        button_is_released(main, main->buttons, main->window, main->scene);
    button_is_hovered(main->buttons, main->window, main->scene);
    cinematic_event(main);
}
