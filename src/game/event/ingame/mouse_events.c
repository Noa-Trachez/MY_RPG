/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Ingame mouse events
*/

#include "my_rpg.h"

void ingame_mouse_event(main_t *main)
{
    ingame_zoom(main);
    if (main->event.type == sfEvtMouseButtonPressed &&
        main->event.mouseButton.button == sfMouseLeft) {
        main->window->oldMousePos =
        sfMouse_getPositionRenderWindow(main->window->screen);
        main->window->isClickHold = 1;
    }
    if (main->event.type == sfEvtMouseButtonReleased &&
        main->event.mouseButton.button == sfMouseLeft)
        main->window->isClickHold = 0;
}
