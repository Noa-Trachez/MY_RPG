/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** INIT doors
*/

#include "my_rpg.h"

void init_doors(main_t *main)
{
    door_t *doors = NULL;
    main->game->doors = NULL;

    for (int i = 0; ALL_DOORS[i].map != END; i++)
        doors = new_door(doors, ALL_DOORS[i]);
    main->game->doors = doors;
}
