/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#ifndef ENEMY_H
    #define ENEMY_H
    #include "projectiles.h"

/////////////////////////////////////////////////////////
///
/// * Health   > h     (int)
/// * Damage   > d     (int)
/// * Speed    > s     (float)
/// * Rect     > r     (sfIntRect)
/// * Scale    > l     (sfVector2f)
/// * Position > p     (sfVector2f)
///
/// > build_enemy(&enemy_struct, "hdsrlp", ...);
///
/////////////////////////////////////////////////////////

    #define ERRMARG(x) (-50 <= (x) && (x) <= 50)
    #ifndef ENEMY_T
        #define ENEMY_T
typedef struct enemies {
    int id;
    int map;
    int health;
    int damage;
    float speed;
    sfVector2f destination;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f pos;
    sfRectangleShape *sprite;
    sfClock *clock;
    sfClock *shot;
    int toBeDestroyed;
    items_t *items;
    projectiles_t *projectiles;
    struct enemies *next;
} enemies_t;
    #endif/*ENEMY_T*/

static const sfIntRect ENEMIES_RECT[5] = {
    {1556, 16, 40, 32},
    {1603, 17, 40, 40},
    {1651, 18, 41, 40},
    {1698, 21, 38, 35},
    {1764, 23, 130, 100},
};

enum ENEMY_TYPE {ENEMY, BOSS};

// DEFAULT ENEMY
static const enemies_t DEFAULT_ENEMY = {ENEMY, MAP, 100, 2, (float)8.0,
(sfVector2f){0, 0}, (sfIntRect){0, 0, 64, 64}, (sfVector2f){1, 1},
(sfVector2f){10, 10}, NULL, NULL, NULL, 0, NULL, NULL, NULL};

// DEFAULT BOSS
static const enemies_t DEFAULT_BOSS = {BOSS, MAP, 8000, 20, (float)4.0,
(sfVector2f){0, 0}, (sfIntRect){0, 0, 64, 64}, (sfVector2f){1, 1},
(sfVector2f){10, 10}, NULL, NULL, NULL, 0, NULL, NULL, NULL};

static const sfVector2f SPAWN_POS[4][2] = {{{ 3792, -2352}, {4012, -2132}},
{{-120, -2208}, {100, -1988}}, {{-2512, 1552}, {-2292, 1772}},
{{-4856, 3192}, {-4636, 3412}}};

// SETTER
enemies_t *enemy_set_health(enemies_t *enemies, va_list list);
enemies_t *enemy_set_damage(enemies_t *enemies, va_list list);
enemies_t *enemy_set_speed(enemies_t *enemies, va_list list);
enemies_t *enemy_set_sprite_rect(enemies_t *enemies, va_list list);
enemies_t *enemy_set_sprite_scale(enemies_t *enemies, va_list list);
enemies_t *enemy_set_sprite_pos(enemies_t *enemies, va_list list);

// STATE
void enemy_display(window_t *window, enemies_t *enemies, int current_map);
void destroy_enemies(enemies_t **enemies);

void show_spawners(sfRenderWindow *window, sfColor color, int spawner);

#endif/*ENEMY_H*/

#ifdef MAIN_T
void spawn_enemy(main_t *main, int number, int unit, int spawner);

// STATE
void enemy_behaviour(main_t *main, enemies_t **enemies, map_t *map);
void enemy_moving(map_t *map, enemies_t *enemies, player_t *player);
void enemy_drop(main_t *main, enemies_t *enemy);
void depop_enemy(enemies_t *enemies);

// BUILDER
void build_enemy(main_t *main, enemies_t **enemies, char *parameters, ...);
void build_boss(main_t *main, enemies_t **enemies, sfVector2f pos);
items_t *build_item_enemies(main_t *main);
void destroy_enemy_id(main_t *main, int type);
int returned(__attribute((unused))main_t *main,
__attribute((unused))items_t *item);
#endif/*MAIN_T*/
