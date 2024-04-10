/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#ifndef PROJECTILES_H
    #define PROJECTILES_H

typedef struct projectiles {
    int damage;
    int speed;
    int toBeDestroyed;
    int lifetime;
    sfVector2f start;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f target;
    sfRectangleShape *sprite;
    sfClock *clock;
    struct projectiles *next;
} projectiles_t;

// DEFAULT PROJECTILE
static const projectiles_t default_projectile = {0, 35, 0, 0,
(sfVector2f){0, 0}, (sfIntRect){0, 0, 0, 0}, (sfVector2f){1, 1},
(sfVector2f){0, 0}, (sfVector2f){0, 0}, NULL, NULL, NULL};
#endif/*PROJECTILES_H*/

#if defined(ENEMY_T) && defined(PLAYER_T)
// PLAYER
void projectile_display(projectiles_t *projectiles, window_t *window);
void projectile_moving(projectiles_t *projectiles);
void projectile_hit(projectiles_t *projectiles, enemies_t *enemies);
void destroy_projectiles(projectiles_t **projectiles);

// ENEMY
void enemy_projectile_behaviour(player_t *player, enemies_t *enemies,
window_t *window);
void enemy_attack(enemies_t *enemies, player_t *player);
void build_multiple_projectiles_enemy(enemies_t *enemy, sfVector2f dest,
int amount);
void build_projectile_enemy(enemies_t *enemy, sfVector2f dest);
void enemy_projectile_display(enemies_t *enemies, window_t *window);
void enemy_projectile_moving(enemies_t *enemies);
void enemy_projectile_hit(enemies_t *enemies, player_t *player);
void destroy_enemy_projectiles(enemies_t *enemies);
#endif

#ifdef PLAYER_T
// BUILDER
void build_projectile(player_t *player, sfVector2f dest,
__attribute__((unused))int type);
void build_multiple_projectiles(player_t *player, sfVector2f dest,
int type, int amount);

// BEHAVIOUR
void projectile_behaviour(player_t *player, enemies_t *enemies,
window_t *window);
#endif/*PLAYER_T*/
