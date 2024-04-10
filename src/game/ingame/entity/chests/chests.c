/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Chests manager
*/

#include "my_rpg.h"

void chest_display(chest_t *chests, window_t *window, int current_map)
{
    chest_t *head = chests;

    while (head) {
        if (head->map != current_map) {
            head = head->next;
            continue;
        }
        sfRenderWindow_drawRectangleShape(window->screen, head->sprite, 0);
        head = head->next;
    }
}

void chest_drop(map_t *map, chest_t *chests,
on_ground_items_t **on_ground_items)
{
    chest_t *head = chests;

    while (head) {
        if (head->map != map->currentMap) {
            head = head->next;
            continue;
        }
        if (head->isOpen == CHEST_OPEN) {
            new_item_list(&head->item, randnb(1, 6), -2);
            drop_item(&head->item, on_ground_items, head->pos,
            map->currentMap);
            head->isOpen = CHEST_DROP;
        }
        if (head->isOpen == CHEST_DROP)
            sfRectangleShape_setTextureRect(head->sprite,
            CHEST_RECT[CHEST_DROP]);
        head = head->next;
    }
}

void chest_behaviour(main_t *main, chest_t *chests,
on_ground_items_t **on_ground_items)
{
    chest_drop(main->game->map, chests, on_ground_items);
}
