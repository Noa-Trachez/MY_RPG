/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Enemy manager
*/

#include "my_rpg.h"

void enemy_behaviour(main_t *main, enemies_t **enemies, map_t *map)
{
    enemy_moving(map, *enemies, main->game->player);
    depop_enemy(main->enemies);
    enemy_drop(main, *enemies);
    destroy_enemies(enemies);
}
