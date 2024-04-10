/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Build projectiles
*/

#include "my_rpg.h"

static projectiles_t *init_projectile_values(player_t *player, sfVector2f dest,
int type)
{
    projectiles_t *projectile = malloc(sizeof(projectiles_t));

    *projectile = default_projectile;
    projectile->speed = (type == SHOTGUN) ? randnb(12, 22) : 30;
    projectile->damage = player->stats->damage;
    projectile->lifetime = 2000;
    projectile->pos = player->pos;
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

void build_projectile(player_t *player, sfVector2f dest, int type)
{
    projectiles_t *projectile = player->projectiles;
    projectiles_t *head = projectile;

    if (projectile != NULL) {
        while (projectile->next != NULL)
            projectile = projectile->next;
        projectile->next = init_projectile_values(player, dest, type);
        projectile = head;
    } else
        projectile = init_projectile_values(player, dest, type);
    player->projectiles = projectile;
}

sfVector2f change_destination(sfVector2f dest)
{
    int sign = (randnb(0, 10) > 5) ? 1 : -1;

    dest = (sfVector2f){dest.x + (randnb(2, 15) * sign),
    dest.y + (randnb(1, 10) * sign)};
    return (dest);
}

void build_multiple_projectiles(player_t *player, sfVector2f dest,
int type, int amount)
{
    for (int i = 0; i < amount; i++) {
        if (type == SHOTGUN)
            dest = change_destination(dest);
        build_projectile(player, dest, type);
    }
}
