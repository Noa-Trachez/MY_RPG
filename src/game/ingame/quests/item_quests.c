/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** item_quests
*/

#include "my_rpg.h"

void create_object(items_t *item, int my_object)
{
    object_t *object = malloc(sizeof(object_t));

    if (item->weapon)
        free(item->weapon);
    if (item->ammo)
        free(item->ammo);
    item->weapon = NULL;
    item->ammo = NULL;
    memset(object, 0, sizeof(object_t));
    object->count = 1;
    item->sprite = sfRectangleShape_create();
    sfRectangleShape_setTexture(item->sprite, get_objects(), 0);
    sfRectangleShape_setTextureRect(item->sprite, OBJECTS_RECTS[my_object]);
    sfRectangleShape_setSize(item->sprite, (sfVector2f){10, 10});
    sfRectangleShape_setScale(item->sprite, (sfVector2f){4, 4});
    item->object = object;
}

void set_item_type_quest(items_t *item, int type, int choose)
{
    void (*fptr[])() =
    {&create_weapon, &create_ammo, &create_food};

    if (type == -1)
        type = get_type(0);
    if (type == -2)
        type = get_type(85);
    fptr[type](item, choose, -1);
}

void create_item_quest(items_t *item, int modifier, int choose)
{
    item->id = randnb(0, 10000);
    set_item_type_quest(item, modifier, choose);
    item->rect = sfRectangleShape_getTextureRect(item->sprite);
    item->next = NULL;
}

items_t *build_item_quest(quest_t *quest)
{
    items_t *item = malloc(sizeof(items_t));
    memset(item, 0, sizeof(items_t));

    if (quest->item[0] == WEAPON)
        create_item_quest(item, quest->item[0], quest->item[1]);
    else
        create_object(item, quest->item[0]);
    item->id = quest->item[1];
    item->next = NULL;
    return (item);
}
