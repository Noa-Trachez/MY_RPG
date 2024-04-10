/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Build a new door
*/

#include "my_rpg.h"

void create_second_door(door_t *new_door, door_t all_door)
{
    new_door->second = sfRectangleShape_create();
    sfRectangleShape_setSize(new_door->second, (sfVector2f){64, 64});
    sfRectangleShape_setTexture(new_door->second, get_objects(), 0);
    sfRectangleShape_setTextureRect(new_door->second, all_door.rect);
    sfRectangleShape_setOrigin(new_door->second, (sfVector2f){32, 32});
    sfRectangleShape_setPosition(new_door->second,
    (sfVector2f){all_door.pos.x + 64, all_door.pos.y});
}

static void init_door_values(door_t *new_door, door_t all_door)
{
    new_door->id = all_door.id;
    new_door->map = all_door.map;
    new_door->nb = all_door.nb;
    new_door->activate = all_door.activate;
    new_door->pos = all_door.pos;
    new_door->range = all_door.range;
    new_door->open = sfClock_create();
    new_door->close = sfClock_create();
    new_door->first = sfRectangleShape_create();
}

door_t *new_door(door_t *door, door_t all_door)
{
    door_t *new_door = malloc(sizeof(door_t));

    memset(new_door, 0, sizeof(door_t));
    init_door_values(new_door, all_door);
    sfRectangleShape_setOrigin(new_door->first, (sfVector2f){32, 32});
    sfRectangleShape_setSize(new_door->first, (sfVector2f){64, 64});
    sfRectangleShape_setTexture(new_door->first, get_objects(), 0);
    sfRectangleShape_setTextureRect(new_door->first, all_door.rect);
    sfRectangleShape_setPosition(new_door->first, all_door.pos);
    if (all_door.nb == DOUBLE)
        create_second_door(new_door, all_door);
    new_door->next = door;
    return new_door;
}
