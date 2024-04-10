/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Projectiles manager
*/

#include "my_rpg.h"

void projectile_behaviour(player_t *player, enemies_t *enemies,
window_t *window)
{
    projectile_moving(player->projectiles);
    projectile_hit(player->projectiles, enemies);
    destroy_projectiles(&player->projectiles);
    enemy_projectile_behaviour(player, enemies, window);
}
