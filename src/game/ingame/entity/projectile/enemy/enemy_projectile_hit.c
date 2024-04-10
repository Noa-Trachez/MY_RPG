/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Enemy projectiles hit
*/

#include "my_rpg.h"

static void projectile_hit_player(projectiles_t *projectile, player_t *player)
{
    if (abs((int)objects_delta(projectile->pos, projectile->start)) >=
    projectile->lifetime)
        projectile->toBeDestroyed = 1;
    if (object_inrange(projectile->pos, player->pos, 30) &&
    !projectile->toBeDestroyed) {
        player->currentHealth -= projectile->damage;
        projectile->toBeDestroyed = 1;
    }
}

void enemy_projectile_hit(enemies_t *enemies, player_t *player)
{
    enemies_t *head_e = enemies;
    projectiles_t *head_p = NULL;

    while (head_e) {
        head_p = head_e->projectiles;
        while (head_p) {
            projectile_hit_player(head_p, player);
            head_p = head_p->next;
        }
        head_e = head_e->next;
    }
}
