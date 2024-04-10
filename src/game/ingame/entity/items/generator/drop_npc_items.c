/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** NPCs item drop
*/

#include "my_rpg.h"

int drop_npc_ammo(main_t *main, int type)
{
    items_t *item = malloc(sizeof(items_t));

    memset(item, 0, sizeof(items_t));
    item->id = randnb(0, 10000);
    set_item_type(item, 1, type);
    item->rect = sfRectangleShape_getTextureRect(item->sprite);
    item->next = NULL;
    drop_item(&item, &main->game->onGroundItems,
    (sfVector2f){SPECS_NPC[0].pos.x, SPECS_NPC[0].pos.y - 200},
    main->game->map->currentMap);
    return (0);
}

int drop_npc_weapon(main_t *main, int weapon)
{
    items_t *item = malloc(sizeof(items_t));

    memset(item, 0, sizeof(items_t));
    item->id = FIRST_WEAPON;
    set_item_type(item, 0, weapon);
    item->rect = sfRectangleShape_getTextureRect(item->sprite);
    item->next = NULL;
    drop_item(&item, &main->game->onGroundItems,
    (sfVector2f){SPECS_NPC[0].pos.x, SPECS_NPC[0].pos.y - 200},
    main->game->map->currentMap);
    return (0);
}
