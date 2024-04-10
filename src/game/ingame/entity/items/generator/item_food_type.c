/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Item food type
*/

#include "my_rpg.h"

static void set_food_texture(items_t *item)
{
    item->sprite = sfRectangleShape_create();
    sfRectangleShape_setTexture(item->sprite, get_interface(), 0);
    sfRectangleShape_setTextureRect(item->sprite, BUTTON_SPRITE[PLUS_ICON]);
    sfRectangleShape_setSize(item->sprite, (sfVector2f){40, 40});
    sfRectangleShape_setScale(item->sprite, (sfVector2f){0.5, 0.5});
}

void create_food(items_t *item, __attribute__((unused))int type)
{
    food_t *food = malloc(sizeof(food_t));

    memset(food, 0, sizeof(food_t));
    food->type = get_type(0);
    food->count = randnb(1, 8);
    item->food = food;
    set_food_texture(item);
}
