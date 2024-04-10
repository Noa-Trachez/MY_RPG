/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Load .txt map layer / obstacles
*/

#include "my_rpg.h"

void new_obstacle(obstacle_t **obstacles, sfVector2f coords, sfFloatRect rect)
{
    obstacle_t *head = *obstacles;

    if (*obstacles) {
        while ((*obstacles)->next != NULL)
            (*obstacles) = (*obstacles)->next;
        (*obstacles)->next = malloc(sizeof(obstacle_t));
        *(*obstacles)->next = (obstacle_t){coords.x, coords.y, rect, NULL};
        *obstacles = head;
    } else {
        *obstacles = malloc(sizeof(obstacle_t));
        **obstacles = (obstacle_t){coords.x, coords.y, rect, NULL};
    }
}

void load_obstacles(obstacle_t **obstacles, const char *obstacles_file,
map_t *map)
{
    float col = 0;
    float row = 0;

    for (int i = 0; obstacles_file[i] && obstacles_file[i] != '}'; i++) {
        if (obstacles_file[i] == ',')
            col += 1;
        if (obstacles_file[i] == ';') {
            row += 1;
            col = 0;
        }
        if (obstacles_file[i] == '1')
            new_obstacle(obstacles, (sfVector2f){col, row},
            (sfFloatRect){(col - (float)map->mapsize.x / 2) * map->tilesize.x,
            (row - (float)map->mapsize.y / 2) * map->tilesize.y,
            map->tilesize.x, map->tilesize.y});
    }
}
