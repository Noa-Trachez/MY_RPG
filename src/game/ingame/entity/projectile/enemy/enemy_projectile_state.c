/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Enemy projectiles state
*/

#include "my_rpg.h"

void enemy_projectile_display(enemies_t *enemies, window_t *window)
{
    enemies_t *head_e = enemies;
    projectiles_t *head_p = NULL;

    while (head_e) {
        head_p = head_e->projectiles;
        while (head_p) {
            sfRenderWindow_drawRectangleShape(window->screen,
            head_p->sprite, 0);
            head_p = head_p->next;
        }
        head_e = head_e->next;
    }
}

static void move_projectile(projectiles_t *projectile)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(projectile->clock)) < 0.02)
        return;
    projectile->pos = sfRectangleShape_getPosition(projectile->sprite);
    sfRectangleShape_move(projectile->sprite, projectile->target);
}

void enemy_projectile_moving(enemies_t *enemies)
{
    enemies_t *head_e = enemies;
    projectiles_t *head_p = NULL;

    while (head_e) {
        head_p = head_e->projectiles;
        while (head_p) {
            move_projectile(head_p);
            head_p = head_p->next;
        }
        head_e = head_e->next;
    }
}
