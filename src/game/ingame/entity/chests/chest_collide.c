/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Chest collision
*/

#include "my_rpg.h"

void add_collide_chest(map_t *map, chest_t *chest, int current_map)
{
    int i = 0;
    chest_t *head = chest;
    sfVector2f array_pos;

    while (head) {
        array_pos = (sfVector2f){(SPECS_CHESTS[i].pos.x / map->tilesize.x +
        (float)(map->mapsize.x / 2)), (SPECS_CHESTS[i].pos.y /
        map->tilesize.y + (float)(map->mapsize.y / 2))};
        if (head->map == current_map && is_in_map(array_pos, map->mapsize)) {
            new_obstacle(&map->obstacles, array_pos,
            (sfFloatRect){(array_pos.x - (float)map->mapsize.x / 2) *
            map->tilesize.x, (array_pos.y - map->mapsize.y / 2.0) *
            map->tilesize.y + map->tilesize.y / 2.3, map->tilesize.x,
            map->tilesize.y / 1.2});
        }
        i++;
        head = head->next;
    }
}
