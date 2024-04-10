/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Particles manager
*/

#include "my_rpg.h"

void particles_manager(particles_t *particles, window_t *window)
{
    display_circle_particles(particles->circleParticles, window);
    display_thruster_particles(particles->thrusterParticles, window);
    display_zzz_particles(particles->zzzParticles, window);
    if (sfTime_asSeconds(sfClock_getElapsedTime(particles->clock)) < 0.02)
        return;
    update_circle_particles(particles->circleParticles);
    update_thruster_particles(particles->thrusterParticles);
    update_zzz_particles(particles->zzzParticles);
    destroy_circle_particles(&particles->circleParticles);
    destroy_thruster_particles(&particles->thrusterParticles);
    destroy_zzz_particles(&particles->zzzParticles);
    sfClock_restart(particles->clock);

}
