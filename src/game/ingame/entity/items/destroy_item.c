/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Destroy item
*/

#include "my_rpg.h"

void free_item(items_t *items)
{
    if (items->weapon != NULL)
        free(items->weapon);
    if (items->ammo != NULL)
        free(items->ammo);
    if (items->food != NULL)
        free(items->food);
    sfRectangleShape_destroy(items->sprite);
    free(items);
}

void delete_item_list(items_t **items)
{
    items_t *head = *items;
    items_t *save;

    if (head) {
        save = head;
        head = save->next;
        *items = head;
        free_item(save);
        save = NULL;
    }
    while (head) {
        if (head->next) {
            save = head->next;
            head->next = save->next;
            free_item(save);
            save = NULL;
        }
        head = head->next;
    }
}

void unequip_item(equipedItems_t *equipedItems, items_t *item)
{
    for (int i = 0; i < 4; i++)
        if (equipedItems->slots[i] == item)
            equipedItems->slots[i] = NULL;
}

void destroy_item(items_t **item_list, items_t *item)
{
    items_t *head = *item_list;
    items_t *save;

    if (head && head == item) {
        save = head;
        head = save->next;
        *item_list = head;
        free_item(save);
        save = NULL;
    }
    while (head) {
        if (head->next && head->next == item) {
            save = head->next;
            head->next = save->next;
            free_item(save);
            save = NULL;
        }
        head = head->next;
    }
}
