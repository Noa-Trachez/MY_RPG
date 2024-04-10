/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** INIT Chests
*/

#include "my_rpg.h"

void init_chests(main_t *main)
{
    main->game->chest = NULL;

    for (int i = 0; SPECS_CHESTS[i].map != END; i++)
        build_chest(&main->game->chest, SPECS_CHESTS[i]);
}
