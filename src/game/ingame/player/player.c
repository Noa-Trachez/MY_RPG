/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Player manager
*/

#include "my_rpg.h"

void player_display(player_t *player, window_t *window)
{
    sfRenderWindow_drawRectangleShape(window->screen, player->sprite, 0);
}

void player_actions(main_t *main)
{
    player_t *player = main->game->player;
    window_t *window = main->window;
    items_t *equiped_items = player->equipedItems->slots
    [player->equipedItems->currentSeclectedItem];

    if (player->currentHealth > 0 && sfTime_asSeconds(sfClock_getElapsedTime
    (player->tick)) > 0.02 && player->state->canMove)
        player_moves(main, player, main->game->map);
    if (player->currentHealth > 0 && sfTime_asSeconds(sfClock_getElapsedTime
    (player->movement)) > 0.1)
        player_movement_animation(player);
    reload_weapon(main->hud, main->game->player);
    if (window->isClickHold && equiped_items && equiped_items->weapon)
        player_attack(player, window);
}

void player_behaviour(main_t *main)
{
    player_t *player = main->game->player;
    window_t *window = main->window;

    player_actions(main);
    player_hitbox(player);
    player_camera(player, window);
    inventory_manager(player, window);
    player->state->canShot = (player->state->inInventory ||
    player->state->inQuests || player->state->isReloading ||
    main->game->map->currentMap != 0) ? 0 : 1;
    if (player->currentHealth <= 0 &&
    sfTime_asSeconds(sfClock_getElapsedTime(player->tick)) > 0.2)
        player_die(main, player);
}
