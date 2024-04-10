/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Build item
*/

#include "my_rpg.h"

void set_item_type(items_t *item, int type, int choose)
{
    void (*fptr[])() =
    {&create_weapon, &create_ammo, &create_food};

    if (type == -1)
        type = get_type(0);
    if (type == -2)
        type = get_type(85);
    fptr[type](item, choose, -1);
}

items_t *build_item(int modifier)
{
    items_t *item = malloc(sizeof(items_t));

    memset(item, 0, sizeof(items_t));
    item->id = randnb(0, 10000);
    set_item_type(item, modifier, -1);
    item->rect = sfRectangleShape_getTextureRect(item->sprite);
    item->next = NULL;
    return (item);
}

static void add_item(items_t **items, int modifier)
{
    items_t *head = *items;

    if (*items) {
        while ((*items)->next != NULL)
            *items = (*items)->next;
        (*items)->next = build_item(modifier);
        *items = head;
    } else
        *items = build_item(modifier);
}

void new_item_list(items_t **items, int count, int modifier)
{
    while (count) {
        add_item(items, modifier);
        count--;
    }
}
