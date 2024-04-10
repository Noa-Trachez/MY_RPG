/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Build common particles
*/

#include "my_rpg.h"

static circle_particles_t *init_particles_circle_values(sfVector2f pos)
{
    circle_particles_t *unit = malloc(sizeof(circle_particles_t));
    float angle = (float)randnb(0, 359);

    memset(unit, 0, sizeof(circle_particles_t));
    unit->radius = (float)randnb(2, 6);
    unit->color = sfWhite;
    unit->shape = sfCircleShape_create();
    unit->direction = angle_to_vector(angle, randnb(1, 2));
    sfCircleShape_setFillColor(unit->shape, unit->color);
    sfCircleShape_setPosition(unit->shape, pos);
    sfCircleShape_setRadius(unit->shape, unit->radius);
    return (unit);
}

void new_circle_particle(circle_particles_t **circle_particles,
sfVector2f pos)
{
    circle_particles_t *head = *circle_particles;

    if (!(*circle_particles))
        (*circle_particles) = init_particles_circle_values(pos);
    else {
        while (head->next != NULL)
            head = head->next;
        head->next = init_particles_circle_values(pos);
    }
}

void new_circle_particles_cluster(particles_t *particles, sfVector2f pos,
int count)
{
    circle_particles_t **circle_particles = &particles->circleParticles;

    for (int i = 0; i < count; i++)
        new_circle_particle(circle_particles,
        (sfVector2f){pos.x - 20, pos.y + 5});
}
