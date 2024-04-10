/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Check if mouse is on quest
*/

#include "my_rpg.h"

void is_mouse_on_quest(main_t *main)
{
    sfIntRect button;

    for (int i = 0; i < 4; i++) {
        button = resize_mouse_rect(main->window, BUTTON_QUEST[i]);
        if (is_mouse_on_object(main->window,
        (sfVector2f){button.left + button.width / 2,
        button.top + button.height / 2},
        (sfVector2f){button.width, button.height},
        (sfVector2f){1, 1}) == 1)
            draw_desc(main, i);
    }
}
