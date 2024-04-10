/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Change sprite rect of a button
*/

#include "my_rpg.h"

void change_sprite(main_t *main, sfIntRect to_replace)
{
    int target = get_global(&g_last_pressed_button);
    int counter = 0;
    buttons_t *head = main->buttons;

    while (main->buttons && (counter < target)) {
        counter++;
        main->buttons = main->buttons->next;
    }
    sfRectangleShape_setTextureRect(main->buttons->sprite, to_replace);
    main->buttons = head;
}
