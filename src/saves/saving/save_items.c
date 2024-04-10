/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Item list saving
*/

#include "my_rpg.h"

int items_len(items_t *items)
{
    items_t *save = items;
    int i = 0;

    while (save) {
        i++;
        save = save->next;
    }
    return i;
}

void save_item(items_t *items, int fd)
{
    int len = items_len(items);

    write(fd, &len, sizeof(int));
    while (items) {
        write(fd, items, sizeof(items_t));
        if (items->ammo)
            write(fd, items->ammo, sizeof(ammo_t));
        if (items->weapon)
            write(fd, items->weapon, sizeof(weapon_t));
        if (items->food)
            write(fd, items->food, sizeof(food_t));
        if (items->object)
            write(fd, items->object, sizeof(object_t));
        items = items->next;
    }
}
