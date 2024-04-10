/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Pause menu event
*/

#include "my_rpg.h"

void pause_menu_event(main_t *main)
{
    if (main->event.type == sfEvtKeyPressed &&
    main->event.key.code == sfKeyEscape)
        return_to_game(main);
}
