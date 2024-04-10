/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** collide_doors
*/

#include "my_rpg.h"

void change_collide(main_t *main, door_t *doors)
{
    obstacle_t *head = main->game->map->obstacles;
    sfVector2f pos_left = sfRectangleShape_getPosition(doors->first);

    for (; head; head = head->next) {
        if (head->obstacle.left == pos_left.x - 32
        && head->obstacle.top == pos_left.y - 32) {
            head->obstacle.width = sfRectangleShape_getSize(doors->first).x;
            head = head->next;
        } else
            continue;
        if (!doors->second)
            continue;
        head->obstacle.left =
        sfRectangleShape_getPosition(doors->second).x - 32;
        head->obstacle.width =
        sfRectangleShape_getSize(doors->second).x;
    }
}

void update_collide_doors(main_t *main)
{
    door_t *head = main->game->doors;

    while (head) {
        if (head->map != main->game->map->currentMap) {
            head = head->next;
            continue;
        }
        change_collide(main, head);
        head = head->next;
    }
}

void add_collide_right_door(map_t *map, door_t *head)
{
    sfVector2f array_pos;

    if (!head->second)
        return;
    array_pos = get_array_pos(sfRectangleShape_getPosition(head->second),
    map->mapsize, map->tilesize);
    if (is_in_map(array_pos, map->mapsize)) {
        new_obstacle(&map->obstacles, array_pos,
        (sfFloatRect){(array_pos.x - (float)map->mapsize.x / 2) *
        map->tilesize.x, (array_pos.y - (float)map->mapsize.y / 2) *
        map->tilesize.y, sfRectangleShape_getSize(head->second).x,
        sfRectangleShape_getSize(head->second).y});
    }
}

void add_collide_doors(map_t *map, door_t *doors, int current_map)
{
    door_t *head = doors;
    sfVector2f array_pos;

    while (head) {
        array_pos = get_array_pos(sfRectangleShape_getPosition(head->first),
        map->mapsize, map->tilesize);
        if (head->map == current_map && is_in_map(array_pos, map->mapsize)) {
            new_obstacle(&map->obstacles, array_pos,
            (sfFloatRect){(array_pos.x - (float)map->mapsize.x / 2) *
            map->tilesize.x, (array_pos.y - (float)map->mapsize.y / 2) *
            map->tilesize.y, sfRectangleShape_getSize(head->first).x,
            sfRectangleShape_getSize(head->first).y});
            add_collide_right_door(map, head);
        }
        head = head->next;
    }
}
