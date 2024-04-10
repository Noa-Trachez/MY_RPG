/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** map_check
*/

#include "my_rpg.h"

int is_in_map(sfVector2f coord, sfVector2i map)
{
    return ((coord.x < 0 || coord.y < 0 || coord.x >= map.x ||
    coord.y >= map.y) ? 0 : 1);
}

sfVector2f get_array_pos(sfVector2f pos, sfVector2i mapsize,
sfVector2f tilesize)
{
    return ((sfVector2f){(pos.x / tilesize.x + (float)(mapsize.x / 2)),
    pos.y / tilesize.y + (float)(mapsize.y / 2)});
}
