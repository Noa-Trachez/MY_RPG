/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Doors manager
*/

#include "my_rpg.h"

void door_behaviour(main_t *main)
{
    move_doors(main);
    update_collide_doors(main);
}
