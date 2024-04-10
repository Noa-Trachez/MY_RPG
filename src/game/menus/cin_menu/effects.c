/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Cinematic effect
*/

#include "my_rpg.h"

void delete_particle_cin(main_t *main)
{
    thruster_particles_t *head = main->particles->thrusterParticles;

    while (head) {
        head->toBeDestroyed = 1;
        head = head->next;
    }
    destroy_thruster_particles(&main->particles->thrusterParticles);
}

void create_particle_cinematic(main_t *main, sfVector2f mode)
{
    new_thruster_particles_cluster(main->particles,
    (sfVector2f) {mode.x * (390), mode.y * (290)}, 2,
    (sfVector2f){150, 210});
    new_thruster_particles_cluster(main->particles,
    (sfVector2f) {mode.x * (390), mode.y * (310)}, 2,
    (sfVector2f){150, 210});
    new_thruster_particles_cluster(main->particles,
    (sfVector2f) {mode.x * (390), mode.y * (340)}, 2,
    (sfVector2f){150, 210});
    new_thruster_particles_cluster(main->particles,
    (sfVector2f) {mode.x * (390), mode.y * (590)}, 2,
    (sfVector2f){150, 210});
    new_thruster_particles_cluster(main->particles,
    (sfVector2f) {mode.x * (390), mode.y * (610)}, 2,
    (sfVector2f){150, 210});
    new_thruster_particles_cluster(main->particles,
    (sfVector2f) {mode.x * (390), mode.y * (640)}, 2,
    (sfVector2f){150, 210});
}

void cond_effect(main_t *main)
{
    sfVector2f mode = {(float)main->window->mode.width / 1920,
    (float)main->window->mode.height / 1080};
    sfRenderWindow_setView(main->window->screen, main->window->menuView);
    if (main->cinematic->scene < 3)
        create_particle_cinematic(main, mode);
    else
        delete_particle_cin(main);
}
