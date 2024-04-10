/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Pathfinder
*/

#include "my_rpg.h"

sfVector2f get_path(map_t *map, sfVector2f pos)
{
    int max = 0;
    sfVector2f destination = (sfVector2f){0, 0};
    sfVector2f array_pos = (sfVector2f){(pos.x / map->tilesize.x +
    (float)(map->mapsize.x / 2)), pos.y / map->tilesize.y +
    (float)(map->mapsize.y / 2)};
    sfVector2f coords[2] = {pos, array_pos};

    pathfinder_up(&max, coords, &destination, map);
    pathfinder_down(&max, coords, &destination, map);
    pathfinder_left(&max, coords, &destination, map);
    pathfinder_right(&max, coords, &destination, map);
    pathfinder_up_left(&max, coords, &destination, map);
    pathfinder_up_right(&max, coords, &destination, map);
    pathfinder_down_left(&max, coords, &destination, map);
    pathfinder_down_right(&max, coords, &destination, map);
    if (max == 0)
        return (pos);
    return (destination);
}
