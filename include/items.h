/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#ifndef ITEMS_H
    #define ITEMS_H
    #define FIRST_WEAPON -50
    #define SPECIAL_PIECE -100
    #define GOLD -150
    #define INGOTS 4
    #define ID_INGOTS -200
    #define IRON 5
    #define ID_IRON -250
    #define URANIUM 6
    #define ID_URANIUM -300

enum ITEM_TYPE {WEAPON, AMMO, FOOD, SPECIAL};
enum ITEM_RARITY {COMMON, RARE, EPIC, LEGENDARY};
enum AMMO_TYPE {LIGHTAMMO, MEDIUMAMMO, HEAVYAMMO, EXPLOSIVEAMMO, SPECIALAMMO};
enum WEAPON_TYPE {PISTOL, SMG, RIFLE, SHOTGUN, SNIPER, LMG, EXPLOSIVE};

static const sfIntRect WEAPONS_RECT[7][9] = {
    {{11, 10, 64, 50}, {12, 71, 50, 40}, {12, 120, 64, 46},
    {9, 177, 86, 42}, {11, 229, 56, 46}, {15, 287, 58, 52},
    {15, 352, 62, 46}, {9, 409, 66, 48}, {12, 469, 57, 44}},
    {{132, 13, 106, 56}, {133, 80, 102, 58}, {131, 155, 100, 54},
    {133, 227, 128, 42}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{294, 14, 128, 42}, {294, 73, 128, 40}, {296, 127, 124, 50},
    {298, 195, 122, 34}, {302, 252, 128, 42}, {304, 303, 128, 52},
    {304, 381, 128, 32}, {305, 436, 128, 38}, {307, 492, 122, 44}},
    {{473, 16, 114, 48}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{626, 17, 128, 44}, {628, 69, 128, 50}, {630, 134, 128, 32},
    {633, 185, 128, 42}, {636, 243, 128, 46}, {638, 314, 128, 24},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{808, 4, 128, 68}, {810, 85, 128, 42}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{987, 10, 128, 47}, {988, 79, 128, 58}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}
};

static const sfIntRect AMMO_RECT[5] = {
    {1401, 13, 45, 31},
    {1401, 48, 46, 31},
    {1405, 85, 46, 41},
    {1401, 126, 54, 34},
    {1408, 168, 36, 39},
};

static const sfIntRect FOOD_RECT[4] = {
    {1, 1, 2, 1},
    {1, 1, 2, 1},
    {1, 4, 2, 4}
};

static const sfIntRect OBJECTS_RECTS[7] = {
    {1498, 160, 32, 41},
    {1498, 160, 32, 41},
    {1182, 219, 40, 40},
    {1181, 119, 36, 36},
    {2183, 2, 74, 64},
    {2051, 1, 59, 57},
    {2395, 10, 52, 52},
};

//============ WEAPON STATS BOARD ==========//

// [WEAPON][RARITY][DAMAGE/ATTACKSPEED/ENDURANCE/CHARGEUR/RELOAD][MIN/MAX]
static const float WEAPON_STATS[7][4][5][2] = {
    {
        {{10, 10}, {5, 5}, {0.5, 0.5}, {10, 10}, {0.8}},
        {{10, 10}, {7, 7}, {0.5, 0.5}, {12, 12}, {0.8}},
        {{12, 12}, {7, 7}, {0.5, 0.5}, {12, 12}, {0.8}},
        {{15, 15}, {8, 8}, {0.5, 0.5}, {15, 15}, {1.0}},
    },
    {
        {{5, 5}, {20, 20}, {1, 1}, {50, 50}, {1.2}},
        {{5, 5}, {25, 25}, {1, 1}, {52, 52}, {1.2}},
        {{7, 7}, {25, 25}, {1, 1}, {55, 55}, {1.2}},
        {{10, 10}, {30, 30}, {1, 1}, {60, 60}, {1.4}},
    },
    {
        {{10, 10}, {30, 30}, {1, 1}, {65, 65}, {1.8}},
        {{12, 12}, {35, 35}, {1, 1}, {70, 70}, {1.8}},
        {{14, 14}, {35, 35}, {1, 1}, {70, 70}, {1.8}},
        {{17, 17}, {40, 40}, {1, 1}, {80, 80}, {1.8}},
    },
    {
        {{50, 50}, {1, 1}, {1, 1}, {5, 5}, {3.0}},
        {{52, 52}, {1, 1}, {1, 1}, {7, 7}, {3.0}},
        {{54, 54}, {1, 1}, {1, 1}, {8, 8}, {3.0}},
        {{60, 60}, {1, 1}, {1, 1}, {10, 10}, {3.0}},
    },
    {
        {{100, 100}, {1, 1}, {1, 1}, {3, 3}, {5.1}},
        {{100, 100}, {1, 1}, {1, 1}, {3, 3}, {5.1}},
        {{100, 100}, {1, 1}, {1, 1}, {3, 3}, {5.1}},
        {{100, 100}, {1, 1}, {1, 1}, {3, 3}, {5.1}},
    },
    {
        {{20, 20}, {20, 22}, {1, 1}, {100, 100}, {10}},
        {{25, 25}, {23, 23}, {1, 1}, {100, 100}, {10}},
        {{25, 25}, {23, 23}, {1, 1}, {100, 100}, {10}},
        {{30, 30}, {25, 25}, {1, 1}, {100, 100}, {10}},
    },
    {
        {{200, 200}, {40, 40}, {1, 1}, {1, 1}, {5.1}},
        {{220, 220}, {40, 40}, {1, 1}, {1, 1}, {5.1}},
        {{220, 220}, {40, 40}, {1, 1}, {1, 1}, {5.1}},
        {{250, 250}, {0.1, 0.1}, {1, 1}, {2, 2}, {5.1}},
    },
};

    #define MIN_DAMAGE(i, j) (int)WEAPON_STATS[i][j][0][0]
    #define MAX_DAMAGE(i, j) (int)WEAPON_STATS[i][j][0][1]
    #define MIN_ATTACK(i, j) (int)WEAPON_STATS[i][j][1][0]
    #define MAX_ATTACK(i, j) (int)WEAPON_STATS[i][j][1][1]
    #define MIN_SPEED(i, j) (int)WEAPON_STATS[i][j][2][0]
    #define MAX_SPEED(i, j) (int)WEAPON_STATS[i][j][2][1]
    #define MAGAZINE(i, j) (int)WEAPON_STATS[i][j][3][0]
    #define RELOAD(i, j) WEAPON_STATS[i][j][4][0]

// ===== STATS =====
typedef struct {
    int damage;
    int health;
    int level;
    int attackSpeed;
    int speed;
    int endurance;
    int pilotSkills;
    float resistance;
    float luck;
} stats_t;

typedef struct {
    int type;
    int rarity;
    int magazine;
    int maxAmmo;
    int ammoType;
    float reloadTime;
    sfIntRect rect;
} weapon_t;

typedef struct {
    int type;
    int count;
    sfIntRect rect;
} ammo_t;

typedef struct {
    int type;
    int count;
    sfIntRect rect;
} food_t;

    #define METAL (-1)
    #define POMME (-2)
    #define NOTHING (-3)
    #define NO_DROP (-4)

typedef struct {
    int type;
    int count;
    sfIntRect rect;
} object_t;

typedef struct items{
    int id;
    weapon_t *weapon;
    ammo_t *ammo;
    food_t *food;
    object_t *object;
    stats_t stats;
    sfRectangleShape *sprite;
    sfIntRect rect;
    struct items *next;
} items_t;

typedef struct onGroundItems{
    int isPickedUp;
    int map;
    items_t *item;
    sfVector2f pos;
    struct onGroundItems *next;
} on_ground_items_t;

// ===== BUILDER =====
items_t *build_item(int modifier);
void new_item_list(items_t **items, int count, int modifier);
void create_object(items_t *item, int my_object);

// RANDOMIZER
int get_type(int min);
int get_rarity(void);
int get_weapon_type(void);
int get_ammo_type(void);

// TYPE
void create_weapon(items_t *item, int type, int rarity);
void create_ammo(items_t *item, int type);
void create_food(items_t *item, __attribute__((unused))int type);
// ==========

// ITEMS
void display_items(map_t *map,
on_ground_items_t *on_ground_items, sfRenderWindow *window);
void set_item_type(items_t *item, int type, int choose);

// ON GROUND ITEMS
void drop_item(items_t **items, on_ground_items_t **on_ground_items,
sfVector2f pos, int current_map);
void store_item(items_t **inventory, items_t **item_list, items_t *item);
void pick_up_item(items_t **inventory, on_ground_items_t **item_list,
items_t *item);
void delete_on_ground_item(on_ground_items_t **item_list, items_t *item);

// DESTROY
void delete_item_list(items_t **items);
void destroy_item(items_t **item_list, items_t *item);

#endif/*ITEMS_H*/
