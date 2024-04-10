/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** chest_builder
*/

#ifndef CHEST_BUILDER_H
    #define CHEST_BUILDER_H

    #include "sprite.h"
    #include "items.h"

enum CHEST_STATE {CHEST_CLOSE, CHEST_OPEN, CHEST_DROP};

static const sfIntRect CHEST_RECT[3] = {
    {1498, 13, 33, 64},
    {1498, 88, 33, 64},
    {1498, 88, 33, 64},
};

typedef struct {
    sfVector2f pos;
    int map;
}all_chests_t;

static const all_chests_t SPECS_CHESTS[] =
{
    {
        {3224, 3768}, MAP
    },

    {
        {1648, 2144}, MAP
    },

    {
        {2696, 1992}, MAP
    },

    {
        {3368, 3496}, MAP
    },

    {
        {-576, 1968}, MAP
    },

    {
        {-1088, 2432}, MAP
    },

    {
        {1528, 6064}, MAP
    },

    {
        {-5192, 2952}, MAP
    },

    {
        {-5256, -1720}, MAP
    },

    {
        {6280, 752}, MAP
    },

    {
        {-912, 3568}, MAP
    },

    {
        {-3784, 3152}, MAP
    },

    {
        {6160, -2984}, MAP
    },

    {
        {3888, 416}, MAP
    },

    {
        {-1784, -2208}, MAP
    },

    {
        {3136, 1344}, MAP
    },

    {
        {3400, -2896}, MAP
    },

    {
        {6168, -656}, MAP
    },

    {
        {END, END}, END
    }
};

typedef struct chest_s {
    int isOpen;
    int map;
    items_t *item;
    sfRectangleShape *sprite;
    sfVector2f pos;
    struct chest_s *next;
} chest_t;

// BUILDER
void build_chest(chest_t **chests, all_chests_t all_chests);

// DISPLAY
void chest_display(chest_t *chests, window_t *window, int current_map);

// STATE
void chest_drop(map_t *map, chest_t *chests,
on_ground_items_t **on_ground_items);
void add_collide_chest(map_t *map, chest_t *chest, int current_map);
#endif/*CHEST_BUILDER_H*/

#ifdef MAIN_T
// STATE
void chest_behaviour(main_t *main, chest_t *chests,
on_ground_items_t **onGroundItems);
#endif/*MAIN_T*/
