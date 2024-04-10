/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Player state
*/

#include "my_rpg.h"

void projectile_display(projectiles_t *projectiles, window_t *window)
{
    projectiles_t *head = projectiles;

    while (head) {
        sfRenderWindow_drawRectangleShape(window->screen, head->sprite, 0);
        head = head->next;
    }
}

void projectile_moving(projectiles_t *projectiles)
{
    projectiles_t *head = projectiles;

    while (head) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(head->clock)) < 0.02) {
            head = head->next;
            continue;
        }
        head->pos = sfRectangleShape_getPosition(head->sprite);
        sfRectangleShape_move(head->sprite, head->target);
        sfClock_restart(head->clock);
        head = head->next;
    }
}

static void free_rectshape(sfRectangleShape *sprite,
projectiles_t *save)
{
    sfRectangleShape_destroy(sprite);
    sfClock_destroy(save->clock);
    free(save);
}

void destroy_projectiles(projectiles_t **projectiles)
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
