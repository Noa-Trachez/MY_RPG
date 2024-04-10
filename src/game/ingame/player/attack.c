/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Player attack
*/

#include "my_rpg.h"

void player_attack(player_t *player, window_t *window)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(player->shot));
    int *magazine = &player->equipedItems->slots
    [player->equipedItems->currentSeclectedItem]->weapon->magazine;
    sfVector2f dest = get_mouse_world_pos(window->screen, window->gameView);

    if (time < 1.0 / player->stats->attackSpeed || !player->state->canShot ||
    !(*magazine))
        return;
    if (player->equipedItems->slots
    [player->equipedItems->currentSeclectedItem]->weapon->type != SHOTGUN)
        build_projectile(player, dest, PISTOL);
    else
        build_multiple_projectiles(player, dest, SHOTGUN, 16);
    *magazine -= 1;
    sfClock_restart(player->shot);
}
