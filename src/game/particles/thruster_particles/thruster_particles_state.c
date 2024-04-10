/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Thruster particles state
*/

#include "my_rpg.h"

void update_thruster_particles(thruster_particles_t *particles)
{
    thruster_particles_t *head = particles;
    sfColor color;

    while (head) {
        sfCircleShape_move(head->shape, head->direction);
        head->radius -= (head->radius > 0) ? (float)0.02 : 0;
        sfCircleShape_setRadius(head->shape, head->radius);
        color = sfCircleShape_getFillColor(head->shape);
        sfCircleShape_setFillColor(head->shape,
        sfColor_fromRGBA(color.r, color.g, color.b, color.a - 1));
        head->toBeDestroyed = (head->radius <= 1) ? 1 : 0;
        head = head->next;
    }
}

void display_thruster_particles(thruster_particles_t *particles,
                                window_t *window)
{
    thruster_particles_t *head = particles;

    while (head) {
        sfRenderWindow_drawCircleShape(window->screen, head->shape, 0);
        head->toBeDestroyed = (head->radius <= 0) ? 1 : 0;
        head = head->next;
    }
}

static void free_shape(thruster_particles_t *particle)
{
    sfCircleShape_destroy(particle->shape);
    free(particle);
}

void destroy_thruster_particles(thruster_particles_t **particles)
{
    thruster_particles_t *head = *particles;
    thruster_particles_t *save;

    if (head && head->toBeDestroyed) {
        save = head;
        head = save->next;
        *particles = head;
        free_shape(save);
        save = NULL;
    }
    while (head) {
        if (head->next && head->next->toBeDestroyed) {
            save = head->next;
            head->next = save->next;
            free_shape(save);
            save = NULL;
        }
        head = head->next;
    }
}
