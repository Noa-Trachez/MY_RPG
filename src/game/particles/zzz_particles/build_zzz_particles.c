/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Build zzz particles
*/

#include "my_rpg.h"

static zzz_particles_t *init_zzz_particles_values(sfVector2f pos)
{
    zzz_particles_t *particle = malloc(sizeof(zzz_particles_t));
    int random = randnb(0, 5);
    float rotation[3] = {0, -55, 0};
    sfVector2f size = {(float)(20 + random), (float)(10 + random)};
    sfVector2f npos[3] = {{pos.x, pos.y - size.y}, {pos.x, pos.y},
    {pos.x, pos.y + size.y}};

    memset(particle, 0, sizeof(zzz_particles_t));
    for (int i = 0; i < 3; i++) {
        particle->shape[i] = sfRectangleShape_create();
        sfRectangleShape_setPosition(particle->shape[i], npos[i]);
        sfRectangleShape_setFillColor(particle->shape[i], sfWhite);
        sfRectangleShape_setSize(particle->shape[i], size);
        sfRectangleShape_setOrigin(particle->shape[i],
        (sfVector2f){size.x / 2, size.y / 2});
        sfRectangleShape_setRotation(particle->shape[i], rotation[i]);
        particle->clock = sfClock_create();
    }
    return (particle);
}

void new_particle_zzz(zzz_particles_t **zzz_particles, sfVector2f pos)
{
    zzz_particles_t *head = *zzz_particles;

    if (!(*zzz_particles))
        (*zzz_particles) = init_zzz_particles_values(pos);
    else {
        while (head->next != NULL)
            head = head->next;
        head->next = init_zzz_particles_values(pos);
    }
}
