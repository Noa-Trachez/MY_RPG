/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Inventory manager
*/

#include "my_rpg.h"

int is_ammo(player_t *player, items_t *item)
{
    if (item->ammo) {
        AMMOCONTAINER(item->ammo->type) += item->ammo->count;
        destroy_item(&player->inventory, item);
        return (1);
    }
    return (0);
}

void sort_inventory(player_t *player)
{
    items_t *head = player->inventory;
    items_t *save;

    while (head) {
        save = head->next;
        if (is_ammo(player, head)) {
            head = save;
            continue;
        }
        head = head->next;
    }
}

void get_item_stats(player_t *player)
{
    equipedItems_t *equipedItems = player->equipedItems;
    stats_t stats;
    stats_t *player_stats = player->stats;

    if (equipedItems->slots[equipedItems->currentSeclectedItem]) {
        stats = equipedItems->slots[equipedItems->currentSeclectedItem]->stats;
        player_stats->damage = stats.damage;
        player_stats->attackSpeed = stats.attackSpeed;
    } else {
        player_stats->damage = 0;
        player_stats->attackSpeed = 0;
    }
}

void inventory_manager(player_t *player, window_t *window)
{
    sort_inventory(player);
    display_sidebar(player, window);
    if (player->state->inInventory)
        inventory_display(player, player->inventory, window,
        (sfVector2i){12, 5});
    get_item_stats(player);
}
