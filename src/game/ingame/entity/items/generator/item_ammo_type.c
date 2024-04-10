/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Item ammo type
*/

#include "my_rpg.h"

static void set_ammo_texture(items_t *item)
{
    item->sprite = sfRectangleShape_create();
    sfRectangleShape_setTexture(item->sprite, get_objects(), 0);
    sfRectangleShape_setTextureRect(item->sprite, AMMO_RECT[item->ammo->type]);
    sfRectangleShape_setSize(item->sprite, (sfVector2f){40, 40});
    sfRectangleShape_setScale(item->sprite, (sfVector2f){0.5, 0.5});
}

void create_ammo(items_t *item, int type)
{
    ammo_t *ammo = malloc(sizeof(ammo_t));

    memset(ammo, 0, sizeof(ammo_t));
    if (type == -1)
        ammo->type = get_ammo_type();
    else
        ammo->type = type;
    ammo->count = randnb(5, 30);
    item->ammo = ammo;
    set_ammo_texture(item);
}
