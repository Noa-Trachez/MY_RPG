/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Load menu events
*/

#include "my_rpg.h"

void save_is_pressed(loadMenu_t *load_menu, window_t *window)
{
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};
    sfVector2f position[3] = {{360, 38}, {811, 38}, {1261, 38}};

    for (int i = 0; i < 3; i++)
        if (is_mouse_on_rect(window,
        (sfIntRect){position[i].x * mode.x, position[i].y * mode.y,
        360 * mode.x, 630 * mode.y})) {
            sfRectangleShape_setPosition(load_menu->rect,
            (sfVector2f){position[i].x * mode.x, position[i].y * mode.y});
            load_menu->selectedSave = i;
        }
}

void load_menu_event(main_t *main)
{
    if (main->event.type == sfEvtKeyPressed &&
    main->event.key.code == sfKeyEscape)
        main->scene = MAIN_MENU;
    if (main->event.type == sfEvtMouseButtonPressed &&
    main->event.mouseButton.button == sfMouseLeft)
        save_is_pressed(main->menu->loadMenu, main->window);
}
