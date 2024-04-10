/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Ingame events
*/

#include "my_rpg.h"

void ingame_event(main_t *main)
{
    ingame_mouse_event(main);
    ingame_interactions(main);
    if (main->event.type == sfEvtKeyPressed &&
    main->event.key.code == sfKeyF1)
        main->debugMode = !main->debugMode;
    if (main->game->player->state->inInventory)
        inventory_event(main);
}
