/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Projectiles hit
*/

#include "my_rpg.h"

static void projectile_hit_enemy(enemies_t *head_e, projectiles_t *head_p)
{
    while (head_e) {
        if (object_inrange(head_p->pos, head_e->pos,
        head_e->rect.width / 1.5) && !head_p->toBeDestroyed) {
            head_e->health -= head_p->damage;
            head_p->toBeDestroyed = 1;
        }
        head_e = head_e->next;
    }
}

void projectile_hit(projectiles_t *projectiles, enemies_t *enemies)
{
    projectiles_t *head_p = projectiles;
    enemies_t *head_e = enemies;

    while (head_p) {
        if (abs((int)objects_delta(head_p->pos, head_p->start)) >=
        head_p->lifetime)
            head_p->toBeDestroyed = 1;
        projectile_hit_enemy(head_e, head_p);
        head_e = enemies;
        head_p = head_p->next;
    }
}
