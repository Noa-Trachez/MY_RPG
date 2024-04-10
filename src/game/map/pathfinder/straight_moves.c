/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Pathfinding straight moves
*/

#include "my_rpg.h"

void pathfinder_up(int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map)
{
    if ((int)coords[1].y == -1)
        return;
    if ((int)coords[1].y > 0) {
        *max = map->pathfinder[(int)coords[1].y - 1][(int)coords[1].x];
        *destination = (sfVector2f){coords[0].x, coords[0].y -
        map->tilesize.y};
    }
}

void pathfinder_down(int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map)
{
    if (coords[1].y < (float)map->mapsize.y - 1 && map->pathfinder[(int)
    coords[1].y + 1][(int)coords[1].x] == -1)
        return;
    if (coords[1].y < (float)map->mapsize.y - 1 && map->pathfinder[(int)
    coords[1].y + 1][(int)coords[1].x] > *max) {
        *max = map->pathfinder[(int)coords[1].y + 1][(int)coords[1].x];
        *destination = (sfVector2f){coords[0].x, coords[0].y +
        map->tilesize.y};
    }
}

void pathfinder_left(int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map)
{
    if ((int)coords[1].x > 0 && map->pathfinder[(int)coords[1].y][(int)
    coords[1].x - 1] == -1)
        return;
    if ((int)coords[1].x > 0 && map->pathfinder[(int)coords[1].y][(int)
    coords[1].x - 1] > *max) {
        *max = map->pathfinder[(int)coords[1].y][(int)coords[1].x - 1];
        *destination = (sfVector2f){coords[0].x - map->tilesize.x,
        coords[0].y};
    }
}

void pathfinder_right(int *max, sfVector2f *coords,
sfVector2f *destination, map_t *map)
{
    if (coords[1].x < (float)map->mapsize.x - 1 && map->pathfinder[(int)
    coords[1].y][(int)coords[1].x + 1] == -1)
        return;
    if (coords[1].x < (float)map->mapsize.x - 1 && map->pathfinder[(int)
    coords[1].y][(int)coords[1].x + 1] > *max) {
        *max = map->pathfinder[(int)coords[1].y][(int)coords[1].x + 1];
        *destination = (sfVector2f){coords[0].x + map->tilesize.x,
        coords[0].y};
    }
}
