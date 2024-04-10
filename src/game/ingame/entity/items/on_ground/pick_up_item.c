/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Pick up item
*/

#include "my_rpg.h"

void pick_up_item(items_t **inventory, on_ground_items_t **item_list,
items_t *item)
{
    items_t *head = *inventory;

    if (*inventory) {
        while ((*inventory)->next != NULL && (*inventory)->id != item->id)
            *inventory = (*inventory)->next;
        if ((*inventory)->id != item->id) {
            (*inventory)->next = item;
            item->next = NULL;
        }
        if (*inventory && (*inventory)->id == item->id && (*inventory)->object)
            (*inventory)->object->count++;
        *inventory = head;
    } else {
        *inventory = item;
        item->next = NULL;
    }
    delete_on_ground_item(item_list, item);
}

void delete_on_ground_item(on_ground_items_t **item_list, items_t *item)
{
    on_ground_items_t *head = *item_list;
    on_ground_items_t *save;

    if (head && head->item == item) {
        save = head;
        head = save->next;
        *item_list = head;
        save = NULL;
    }
    while (head) {
        if (head->next && head->next->item == item) {
            save = head->next;
            head->next = save->next;
            save = NULL;
        }
        head = head->next;
    }
}
