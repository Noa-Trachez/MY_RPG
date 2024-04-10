/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#ifndef PLAYER_H
    #define PLAYER_H

// ===== AMMO CONTAINER =====
    #define AMMOCONTAINER(i) ((int*)player->ammo)[i]
    #pragma pack(push, 1)
typedef struct {
    int lightAmmo;
    int mediumAmmo;
    int heavyAmmo;
    int explosiveAmmo;
    int specialAmmo;
} ammoContainer_t;
    #pragma pack(pop)

// ===== EQUIPED ITEMS =====
typedef struct {
    int equipmentSlot;
    int currentSeclectedItem;
    items_t *slots[4];
    sfRectangleShape *equipmentSlotRect;
} equipedItems_t;

// ===== PLAYER STATE =====
typedef struct {
    int inStats;
    int inInventory;
    int inQuests;
    int inInteraction;
    int canShot;
    int canMove;
    int canZoom;
    int isReloading;
} playerState_t;

// ===== PLAYER_T =====
    #include "projectiles.h"
typedef struct {
    int currentHealth;
    sfVector2f pos;
    sfVector2i dir;
    sfRectangleShape *sprite;
    sfFloatRect hitbox[4];
    sfClock *shot;
    sfClock *tick;
    sfClock *reload;
    sfClock *movement;
    stats_t *stats;
    playerState_t *state;
    projectiles_t *projectiles;
    items_t *inventory;
    equipedItems_t *equipedItems;
    ammoContainer_t *ammo;
} player_t;
    #define PLAYER_T 1

// INIT
void player_init(player_t *player);

static const sfIntRect hitboxes[4] = {
        {0, 15, -40, -20},
        {0, 0, 40, -30},
        {40, 0, 0, 0},
        {0, 35, 40, -30},
};

// MOVEMENTS
void player_hitbox(player_t *player);
int player_collision(sfIntRect box, map_t *map);
void player_camera(player_t *player, window_t *window);

// ATTACK
void player_attack(player_t *player, window_t *window);

// ANIMATIONS
void set_player_dir(player_t *player, int index);
void player_movement_animation(player_t *player);
void player_display(player_t *player, window_t *window);

// INVENTORY
void inventory_manager(player_t *player, window_t *window);
void sort_inventory(player_t *player);
void resize_inventory(window_t *window, sfSprite *sprite);
sfIntRect resize_mouse_slots(window_t *window, sfIntRect rect);
void inventory_display(player_t *player, items_t *inventory, window_t *window,
sfVector2i size);
void display_inventory_ammo(window_t *window, ammoContainer_t *ammo_container);
void unequip_item(equipedItems_t *equipedItems, items_t *item);

// SIDEBAR
void display_sidebar(player_t *player, window_t *window);
void display_sidebar_items(player_t *player, window_t *window);
void display_sidebar_ammo(player_t *player, window_t *window);
void display_sidebar_total_ammo(player_t *player, window_t *window);
#endif/*PLAYER_H*/

#ifdef MAIN_T
// ===== BEHAVIOUR =====
void player_behaviour(main_t *main);
void player_moves(main_t *main, player_t *player, map_t *map);
void reload_weapon(hud_t *hud, player_t *player);
void player_die(main_t *main, player_t *player);

// INTERACTIONS
void player_interact(main_t *main, player_t *player, chest_t *chests,
on_ground_items_t **on_ground_items);
void on_ground_item_behaviour(map_t *map, on_ground_items_t **on_ground_items,
player_t *player);

//LIFE
void init_life(main_t *main);
void draw_life(main_t *main);
#endif/*MAIN_T*/
