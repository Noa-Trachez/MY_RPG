/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** INIT Player
*/

#include "my_rpg.h"

void player_stats_init(stats_t *stats)
{
    stats->damage = 0;
    stats->health = 100;
    stats->level = 50;
    stats->attackSpeed = 1;
    stats->speed = 8;
    stats->endurance = 10;
    stats->pilotSkills = 10;
    stats->resistance = 10;
    stats->luck = 10;
}

void player_state_init(playerState_t *playerState)
{
    playerState->inStats = 0;
    playerState->inInventory = 0;
    playerState->inQuests = 0;
    playerState->inInteraction = 0;
    playerState->canShot = 0;
    playerState->canMove = 0;
    playerState->canZoom = 0;
    playerState->isReloading = 0;
}

void init_player_stucts(player_t *player)
{
    player->stats = malloc(sizeof(stats_t));
    player->state = malloc(sizeof(playerState_t));
    player->ammo = malloc(sizeof(ammoContainer_t));
    player->equipedItems = malloc(sizeof(equipedItems_t));
    memset(player->ammo, 0, sizeof(ammoContainer_t));
    memset(player->equipedItems, 0, sizeof(equipedItems_t));
    player->projectiles = NULL;
    player->inventory = NULL;
}

void init_selector_rect(player_t *player)
{
    player->equipedItems->equipmentSlotRect = sfRectangleShape_create();
    sfRectangleShape_setSize(player->equipedItems->equipmentSlotRect,
    (sfVector2f){130, 130});
    sfRectangleShape_setFillColor(player->equipedItems->equipmentSlotRect,
    sfTransparent);
    sfRectangleShape_setOutlineColor
    (player->equipedItems->equipmentSlotRect, sfWhite);
    sfRectangleShape_setOutlineThickness
    (player->equipedItems->equipmentSlotRect, 2);
}

void player_init(player_t *player)
{
    init_player_stucts(player);
    player->pos = (sfVector2f){1680, -864};
    player->sprite = sfRectangleShape_create();
    sfRectangleShape_setTexture(player->sprite, get_character(), 0);
    sfRectangleShape_setTextureRect(player->sprite, CHARACTER[0][MOVE_UP][0]);
    player_stats_init(player->stats);
    player_state_init(player->state);
    player->shot = sfClock_create();
    player->tick = sfClock_create();
    player->reload = sfClock_create();
    player->movement = sfClock_create();
    player->currentHealth = player->stats->health;
    init_selector_rect(player);
}
