/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Settings menu event
*/

#include "my_rpg.h"

void settings_menu_event(main_t *main)
{
    if (main->event.type == sfEvtKeyPressed &&
    main->event.key.code == sfKeyEscape)
        goto_menu(main);
}
