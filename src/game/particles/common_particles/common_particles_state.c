/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Common particles state
*/

#include "my_rpg.h"

void update_circle_particles(circle_particles_t *particles)
{
    circle_particles_t *head = particles;
    sfColor color;

    while (head) {
        sfCircleShape_move(head->shape, head->direction);
        head->radius -= (head->radius > 0) ? (float)0.02 : 0;
        sfCircleShape_setRadius(head->shape, head->radius);
        color = head->color;
        sfCircleShape_setFillColor(head->shape,
        sfColor_fromRGBA(color.r, color.g, color.b, color.a - 1));
        head->toBeDestroyed = (head->radius <= 1) ? 1 : 0;
        head = head->next;
    }
}

void display_circle_particles(circle_particles_t *particles, window_t *window)
{
    circle_particles_t *head = particles;

    while (head) {
        sfRenderWindow_drawCircleShape(window->screen, head->shape, 0);
        head->toBeDestroyed = (head->radius <= 0) ? 1 : 0;
        head = head->next;
    }
}

void destroy_circle_particles(circle_particles_t **particles)
{
    circle_particles_t *head = *particles;
    circle_particles_t *save;
    if (head && head->toBeDestroyed) {
        save = head;
        head = save->next;
        *particles = head;
        sfCircleShape_destroy(save->shape);
        free(save);
        save = NULL;
    }
    while (head) {
        if (head->next && head->next->toBeDestroyed) {
            save = head->next;
            head->next = save->next;
            sfCircleShape_destroy(save->shape);
            free(save);
            save = NULL;
        }
        head = head->next;
    }
}
