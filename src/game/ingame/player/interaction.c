/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Player interaction
*/

#include "my_rpg.h"

void player_interact_item(on_ground_items_t **on_ground_items,
player_t *player)
{
    on_ground_items_t *head = *on_ground_items;

    while (head) {
        if (object_inrange(player->pos, head->pos, 200))
            head->isPickedUp = 1;
        head = head->next;
    }
}

void player_interact_chest(map_t *map, chest_t *chests, player_t *player)
{
    chest_t *head = chests;
    sfVector2f chest_rect;

    while (head) {
        if (head->map != map->currentMap) {
            head = head->next;
            continue;
        }
        chest_rect = (sfVector2f){sfRectangleShape_getPosition(head->sprite).x,
        sfRectangleShape_getPosition(head->sprite).y};
        if (head->isOpen == CHEST_CLOSE &&
        object_inrange(player->pos, chest_rect, 80)) {
            sfRectangleShape_setTextureRect(head->sprite,
            CHEST_RECT[CHEST_OPEN]);
            head->isOpen = CHEST_OPEN;
        }
        head = head->next;
    }
}

void player_interact(main_t *main, player_t *player, chest_t *chests,
on_ground_items_t **on_ground_items)
{
    player_interact_item(on_ground_items, player);
    player_interact_chest(main->game->map, chests, player);
}
