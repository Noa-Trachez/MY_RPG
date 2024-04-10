/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#ifndef PARTICLES_H
    #define PARTICLES_H

// COMMON PARTICLES
typedef struct circleParticles_s {
    int toBeDestroyed;
    float radius;
    sfColor color;
    sfCircleShape *shape;
    sfVector2f direction;
    struct circleParticles_s *next;
} circle_particles_t;

// THRUSTER PARTICLES
typedef struct thrusterParticles_s {
    int toBeDestroyed;
    float radius;
    sfCircleShape *shape;
    sfVector2f direction;
    struct thrusterParticles_s *next;
} thruster_particles_t;

// SLEEPING PARTICLES
typedef struct zzzParticles_s {
    int toBeDestroyed;
    int offset;
    sfRectangleShape *shape[3];
    sfClock *clock;
    struct zzzParticles_s *next;
} zzz_particles_t;

// MAIN STRUCT
typedef struct particles_s {
    circle_particles_t *circleParticles;
    thruster_particles_t *thrusterParticles;
    zzz_particles_t *zzzParticles;
    sfClock *clock;
} particles_t;

// MANAGER
void particles_manager(particles_t *particles, window_t *window);

// COMMON PARTICLES
void new_circle_particles_cluster(particles_t *particles, sfVector2f pos,
int count);
void new_circle_particle(circle_particles_t **circle_particles,
sfVector2f pos);
void update_circle_particles(circle_particles_t *particles);
void display_circle_particles(circle_particles_t *particles, window_t *window);
void destroy_circle_particles(circle_particles_t **particles);

// THRUSTER PARTICLES
void new_thruster_particles_cluster(particles_t *particles, sfVector2f pos,
int count, sfVector2f dir);
void new_thruster_particle(thruster_particles_t **circle_particles,
sfVector2f pos, sfVector2f dir);
void update_thruster_particles(thruster_particles_t *particles);
void display_thruster_particles(thruster_particles_t *particles,
window_t *window);
void destroy_thruster_particles(thruster_particles_t **particles);

// ZZZ PARTICLES
void new_particle_zzz(zzz_particles_t **zzz_particles, sfVector2f pos);
void update_zzz_particles(zzz_particles_t *zzz_particles);
void display_zzz_particles(zzz_particles_t *zzz_particles, window_t *window);
void destroy_zzz_particles(zzz_particles_t **zzz_particles);

#endif/*PARTICLES_H*/
