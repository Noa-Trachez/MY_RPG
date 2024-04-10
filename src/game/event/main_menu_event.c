/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Main menu event
*/

#include "my_rpg.h"

void main_menu_event(main_t *main)
{
    if (main->event.type == sfEvtKeyPressed &&
    main->event.key.code == sfKeyEscape)
        sfRenderWindow_close(main->window->screen);
}
