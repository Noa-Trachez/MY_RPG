/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** On ground items manager
*/

#include "my_rpg.h"

void on_ground_item_behaviour(map_t *map, on_ground_items_t **on_ground_items,
player_t *player)
{
    on_ground_items_t *head = *on_ground_items;

    while (head) {
        if (head->map != map->currentMap) {
            head = head->next;
            continue;
        }
        if (head->isPickedUp)
            sfRectangleShape_move(head->item->sprite, move_towards(head->pos,
            player->pos, 10));
        head->pos = sfRectangleShape_getPosition(head->item->sprite);
        if (head->isPickedUp && object_inrange(player->pos, head->pos, 50))
            pick_up_item(&player->inventory, on_ground_items, head->item);
        head = head->next;
    }
}

static on_ground_items_t *copy_item(items_t *items, int current_map)
{
    on_ground_items_t *on_ground = malloc(sizeof(on_ground_items_t));

    on_ground->isPickedUp = 0;
    on_ground->item = items;
    on_ground->map = current_map;
    on_ground->pos = (sfVector2f){0, 0};
    on_ground->next = NULL;
    return (on_ground);
}

void new_on_ground_item(items_t *items, on_ground_items_t **on_ground_items,
sfVector2f pos, int current_map)
{
    on_ground_items_t *head = *on_ground_items;
    sfVector2f spawn_pos = (sfVector2f) {pos.x + randnb(30, 40) *
    (randnb(0, 1) ? -1 : 1), pos.y + randnb(30, 40) * (randnb(0, 1) ? -1 : 1)};

    if (*on_ground_items) {
        while ((*on_ground_items)->next != NULL)
            *on_ground_items = (*on_ground_items)->next;
        (*on_ground_items)->next = copy_item(items, current_map);
        (*on_ground_items)->next->pos = spawn_pos;
        sfRectangleShape_setPosition((*on_ground_items)->next->item->sprite,
        spawn_pos);
        *on_ground_items = head;
    } else {
        *on_ground_items = copy_item(items, current_map);
        (*on_ground_items)->pos = spawn_pos;
        sfRectangleShape_setPosition((*on_ground_items)->item->sprite,
        spawn_pos);
    }
}

void drop_item(items_t **items, on_ground_items_t **on_ground_items,
sfVector2f pos, int current_map)
{
    items_t *head = *items;

    if (head && !head->sprite)
        return;
    while (head) {
        new_on_ground_item(head, on_ground_items, pos, current_map);
        head = head->next;
    }
    *items = NULL;
}

void display_items(map_t *map, on_ground_items_t *on_ground_items,
sfRenderWindow *window)
{
    on_ground_items_t *head = on_ground_items;

    while (head) {
        if (head->map != map->currentMap) {
            head = head->next;
            continue;
        }
        sfRenderWindow_drawRectangleShape(window, head->item->sprite, 0);
        head = head->next;
    }
}
