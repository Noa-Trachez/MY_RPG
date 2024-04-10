/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Enemy attack
*/

#include "my_rpg.h"

void enemy_attack(enemies_t *enemies, player_t *player)
{
    enemies_t *head = enemies;

    while (head) {
        if (!object_inrange(head->pos, player->pos, 430) ||
        sfTime_asSeconds(sfClock_getElapsedTime(head->shot)) < 2) {
            head = head->next;
            continue;
        }
        build_projectile_enemy(head, player->pos);
        sfClock_restart(head->shot);
        head = head->next;
    }
}

static void free_rectshape(sfRectangleShape *sprite, projectiles_t *save)
{
    sfRectangleShape_destroy(sprite);
    sfClock_destroy(save->clock);
    free(save);
}

static void free_enemy_projectiles(projectiles_t **projectiles)
{
    projectiles_t *head = *projectiles;
    projectiles_t *save;

    if (head && head->toBeDestroyed) {
        save = head;
        head = save->next;
        *projectiles = head;
        free_rectshape(save->sprite, save);
        save = NULL;
    }
    while (head) {
        if (head->next && head->next->toBeDestroyed) {
            save = head->next;
            head->next = save->next;
            free_rectshape(save->sprite, save);
            save = NULL;
        }
        head = head->next;
    }
}

void destroy_enemy_projectiles(enemies_t *enemies)
{
    enemies_t *head_e = enemies;

    while (head_e) {
        free_enemy_projectiles(&head_e->projectiles);
        head_e = head_e->next;
    }
}
