/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#ifndef MAPS_H
    #define MAPS_H
    #define END -1

    #define PATHFINDER_RANGE 30

enum MAPS {MAP, SPACESHIP, ENGINE_ROOM};
enum DOORS {SIMPLE, DOUBLE};
enum DOORS_STATE {DISABLE, ENABLE};
enum DOORS_ID {DOOR_SPACESHIP_MAIN, DOOR_SPACESHIP_MACHINE, DOOR_ENGINE_ROOM,
DOOR_ARENA};

// ===== DOOR_T =====
typedef struct door_s {
    int id;
    int map;
    int nb;
    int activate;
    int range;
    sfIntRect rect;
    sfVector2f pos;
    sfRectangleShape *first;
    sfRectangleShape *second;
    sfClock *open;
    sfClock *close;
    struct door_s *next;
} door_t;

static const door_t ALL_DOORS[] =
{
    {
        DOOR_SPACESHIP_MAIN,
        SPACESHIP,
        DOUBLE,
        ENABLE,
        150,
        (sfIntRect){1498, 160, 32, 41},
        (sfVector2f){-64, 320},
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },

    {
        DOOR_SPACESHIP_MACHINE,
        SPACESHIP,
        DOUBLE,
        ENABLE,
        85,
        (sfIntRect){1498, 160, 32, 41},
        (sfVector2f){448, 832},
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },

    {
        DOOR_ENGINE_ROOM,
        ENGINE_ROOM,
        DOUBLE,
        DISABLE,
        85,
        (sfIntRect){1498, 160, 32, 41},
        (sfVector2f){-192, -704},
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },

    {
        DOOR_ARENA,
        MAP,
        DOUBLE,
        DISABLE,
        100,
        (sfIntRect){1498, 206, 32, 64},
        (sfVector2f){5375, 3712},
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },

    {
        END,
        END,
        END,
        END,
        END,
        (sfIntRect){END, END, END, END},
        (sfVector2f){END, END},
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    }
};

// ===== TP_T =====
typedef struct tp_s {
    sfIntRect rect;
    sfVector2f spawn;
    int actual;
    int go_to;
    int activate;
} tp_t;

static const tp_t ALL_TP[] = {
    {{-2696, -336, 75, 288}, {0, 550}, MAP, SPACESHIP, 0}, // MAP->SPACESHIP
    {{-2696, -336, 75, 288}, {-541, -803}, 0, 2, 0}, // MAP->ENGINE ROOM
    {{-581, -893, 75, 75}, {-2160, -224}, 2, 0, 1}, // ENGINE ROOM->MAP
    {{-45, 718, 90, 90}, {-2160, -224}, 1, 0, 1}, // SPACESHIP->MAP
    {{468, 978, 90, 90}, {-158, -923}, 1, 2, 1}, // SPACESHIP->ENGINE ROOM
    {{-206, -1067, 90, 90}, {481, 918}, 2, 1, 1}, // ENGINE ROOM->SPACESHIP
    {{END, END, END, END}, {END, END}, END, END, END} // NULL
};

// ===== OBSTACLES =====
typedef struct obstacles {
    int x;
    int y;
    sfFloatRect obstacle;
    struct obstacles *next;
} obstacle_t;

// ===== MAP =====
__attribute__((unused))static const char *MAPS[6] = {
    "assets/maps/map01.png",
    "assets/maps/map01.txt",
    "assets/maps/spaceship.png",
    "assets/maps/spaceship.txt",
    "assets/maps/machine.png",
    "assets/maps/machine.txt",
};

typedef struct map {
    int currentMap;
    int **pathfinder;
    sfVector2i mapsize;
    sfVector2f tilesize;
    obstacle_t *obstacles;
    sfSprite *map;
} map_t;

// MAP LOADING
char *read_map_file(char const *path);
void load_map(map_t *map, char const *path);
void new_obstacle(obstacle_t **obstacles, sfVector2f coords, sfFloatRect rect);
void load_obstacles(obstacle_t **obstacles, const char *obstacles_file,
map_t *map);
sfVector2f get_array_pos(sfVector2f pos, sfVector2i mapsize,
sfVector2f tilesize);
int is_in_map(sfVector2f coord, sfVector2i map);

// PATHFINDING GRID
void init_pathfinding_grid(map_t *map);
void refresh_paths(map_t *map, int y, int x, int distance);

// PATHFINDING
sfVector2f get_path(map_t *map, sfVector2f pos);

// PATHFINDING MOVES
void pathfinder_up(int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map);
void pathfinder_down(int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map);
void pathfinder_left(int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map);
void pathfinder_right(int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map);
void pathfinder_up_left(int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map);
void pathfinder_up_right(int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map);
void pathfinder_down_left(int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map);
void pathfinder_down_right(const int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map);

#endif/*MAPS_H*/

#ifdef MAIN_T

//TP
void init_tp(main_t *main);
void check_tp(game_t *game, player_t *player, sfIntRect player_rect,
map_t *map);

// MAP SWITCHING
void switch_map(map_t *map, game_t *game, int mapno);

//DOORS
void init_doors(main_t *main);
void door_behaviour(main_t *main);
void doors_display(main_t *main);
door_t *new_door(door_t *door, door_t all_door);
void move_doors(main_t *main);
int toggle_doors(main_t *main, int id);
void add_collide_doors(map_t *map, door_t *doors, int current_map);
void update_collide_doors(main_t *main);

#endif/*MAIN_T*/
