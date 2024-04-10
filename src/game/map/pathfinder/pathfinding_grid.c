/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Pathfinding grid
*/

#include "my_rpg.h"

void init_pathfinding_grid(map_t *map)
{
    int x_size = map->mapsize.x;

    map->pathfinder = malloc(sizeof(int *) * (map->mapsize.y));
    for (int y = 0; y < map->mapsize.y; y++) {
        map->pathfinder[y] = malloc(sizeof(int) * x_size);
        memset(map->pathfinder[y], 0, sizeof(int) * x_size);
    }
}

static void place_obstacle(map_t *map, sfVector2i pos, sfVector2i size)
{
    int x_pos = pos.x + size.x / 2;
    int y_pos = pos.y + size.y / 2;

    for (int y = pos.y - size.y / 2; y <= y_pos; y++)
        for (int x = pos.x - size.x / 2; x <= x_pos; x++)
            map->pathfinder[y][x] = -1;
}

static void generate_obstacles(map_t *map)
{
    obstacle_t *head = map->obstacles;

    while (head) {
        place_obstacle(map, (sfVector2i){head->x, head->y}, (sfVector2i)
        {head->obstacle.width / map->tilesize.x, head->obstacle.height /
        map->tilesize.y});
        head = head->next;
    }
}

static void generate_grid(map_t *map, int y, int x, int distance)
{
    obstacle_t *head = map->obstacles;

    if (map->pathfinder[y][x] != -1)
        map->pathfinder[y][x] = distance;
    else
        return;
    map->obstacles = head;
    if (y > 0 && map->pathfinder[y - 1][x] < (distance - 1))
        generate_grid(map, y - 1, x, distance - 1);
    if (y < map->mapsize.y - 1 && map->pathfinder[y + 1][x] < (distance - 1))
        generate_grid(map, y + 1, x, distance - 1);
    if (x > 0 && map->pathfinder[y][x - 1] < (distance - 1))
        generate_grid(map, y, x - 1, distance - 1);
    if (x < map->mapsize.x - 1 && map->pathfinder[y][x + 1] < (distance - 1))
        generate_grid(map, y, x + 1, distance - 1);
}

void refresh_paths(map_t *map, int y, int x, int distance)
{
    for (int row = 0; row < map->mapsize.y; row++)
        memset(map->pathfinder[row], 0, sizeof(int) * map->mapsize.x);
    generate_obstacles(map);
    generate_grid(map, y, x, distance);
}
