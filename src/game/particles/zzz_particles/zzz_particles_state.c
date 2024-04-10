/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** zzz particles state
*/

#include "my_rpg.h"

void update_zzz_particles(zzz_particles_t *zzz_particles)
{
    zzz_particles_t *head;
    int sign;
    float random;

    for (head = zzz_particles; head; head = head->next) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(head->clock)) < 0.02)
            continue;
        for (int i = 0; i < 3; i++)
            sfRectangleShape_move(head->shape[i], (sfVector2f){0, -1});
        if (sfTime_asSeconds(sfClock_getElapsedTime(head->clock)) < 0.05)
            continue;
        sign = (randnb(0, 10) > 5) ? -1 : 1;
        random = (float)(randnb(0, 3) * sign);
        for (int i = 0; i < 3; i++)
            sfRectangleShape_move(head->shape[i], (sfVector2f){random, -1});
        head->offset += 1;
        sfClock_restart(head->clock);
    }
}

void display_zzz_particles(zzz_particles_t *zzz_particles, window_t *window)
{
    zzz_particles_t *head = zzz_particles;

    while (head) {
        for (int i = 0; i < 3; i++)
            sfRenderWindow_drawRectangleShape(window->screen,
            head->shape[i], 0);
        head->toBeDestroyed = (head->offset > 35) ? 1 : 0;
        head = head->next;
    }
}

void free_zzz_particles(zzz_particles_t *zzz_particles)
{
    for (int i = 0; i < 3; i++)
        sfRectangleShape_destroy(zzz_particles->shape[i]);
    free(zzz_particles);
}

void destroy_zzz_particles(zzz_particles_t **zzz_particles)
{
    zzz_particles_t *head = *zzz_particles;
    zzz_particles_t *save;

    if (head && head->toBeDestroyed) {
        save = head;
        head = save->next;
        *zzz_particles = head;
        free_zzz_particles(save);
        save = NULL;
    }
    while (head) {
        if (head->next && head->next->toBeDestroyed) {
            save = head->next;
            head->next = save->next;
            free_zzz_particles(save);
            save = NULL;
        }
        head = head->next;
    }
}
