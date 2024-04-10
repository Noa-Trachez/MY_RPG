/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Build thruster particles
*/

#include "my_rpg.h"

static thruster_particles_t *init_particles_thruster_values(sfVector2f pos,
sfVector2f dir)
{
    thruster_particles_t *unit = malloc(sizeof(thruster_particles_t));
    float angle = (float)randnb(dir.x, dir.y);

    memset(unit, 0, sizeof(thruster_particles_t));
    unit->radius = (float)randnb(2, 6);
    unit->shape = sfCircleShape_create();
    unit->direction = angle_to_vector(angle, randnb(1, 2));
    sfCircleShape_setFillColor(unit->shape,
    (sfColor_fromRGB(randnb(200, 255), (randnb(0, 10) > 5) ? 100 : 30, 10)));
    sfCircleShape_setPosition(unit->shape, pos);
    sfCircleShape_setRadius(unit->shape, unit->radius);
    return (unit);
}

void new_thruster_particle(thruster_particles_t **thruster_particles,
sfVector2f pos, sfVector2f dir)
{
    thruster_particles_t *head = *thruster_particles;

    if (!(*thruster_particles))
        (*thruster_particles) = init_particles_thruster_values(pos, dir);
    else {
        while (head->next != NULL)
            head = head->next;
        head->next = init_particles_thruster_values(pos, dir);
    }
}

void new_thruster_particles_cluster(particles_t *particles, sfVector2f pos,
int count, sfVector2f dir)
{
    thruster_particles_t **thruster_particles = &particles->thrusterParticles;

    for (int i = 0; i < count; i++)
        new_thruster_particle(thruster_particles,
        (sfVector2f){pos.x - 20, pos.y + 5}, dir);
}
