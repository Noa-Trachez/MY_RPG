/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Enemy projectiles manager
*/

#include "my_rpg.h"

void enemy_projectile_behaviour(player_t *player, enemies_t *enemies,
window_t *window)
{
    enemy_attack(enemies, player);
    enemy_projectile_moving(enemies);
    enemy_projectile_hit(enemies, player);
    enemy_projectile_display(enemies, window);
    destroy_enemy_projectiles(enemies);
}
