/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Enemy attack
*/

#include "my_rpg.h"

static projectiles_t *init_projectile_values(enemies_t *enemy,
sfVector2f dest)
{
    projectiles_t *projectile = malloc(sizeof(projectiles_t));

    *projectile = default_projectile;
    projectile->speed = 8;
    projectile->damage = enemy->damage;
    projectile->lifetime = 1000;
    projectile->pos = enemy->pos;
    projectile->start = projectile->pos;
    projectile->sprite = sfRectangleShape_create();
    projectile->target = move_towards(projectile->pos, dest,
    (float)projectile->speed);
    projectile->clock = sfClock_create();
    sfRectangleShape_setSize(projectile->sprite, (sfVector2f){5, 10});
    sfRectangleShape_setTexture(projectile->sprite, get_objects(), 0);
    sfRectangleShape_setTextureRect(projectile->sprite,
    (sfIntRect){1287, 147, 10, 20});
    sfRectangleShape_setRotation(projectile->sprite,
    face_towards(projectile->pos, dest));
    sfRectangleShape_setPosition(projectile->sprite, projectile->pos);
    return (projectile);
}

void build_projectile_enemy(enemies_t *enemy, sfVector2f dest)
{
    projectiles_t *projectile = enemy->projectiles;
    projectiles_t *head = projectile;

    if (projectile != NULL) {
        while (projectile->next != NULL)
            projectile = projectile->next;
        projectile->next = init_projectile_values(enemy, dest);
        projectile = head;
    } else
        projectile = init_projectile_values(enemy, dest);
    enemy->projectiles = projectile;
}

void build_multiple_projectiles_enemy(enemies_t *enemy, sfVector2f dest,
int amount)
{
    for (int i = 0; i < amount; i++)
        build_projectile_enemy(enemy, dest);
}
