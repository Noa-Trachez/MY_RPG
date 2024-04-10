/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Player weapon reloading
*/

#include "my_rpg.h"

void reset_reloading(player_t *player, weapon_t **current_weapon, hud_t *hud)
{
    *current_weapon = NULL;
    player->state->isReloading = 0;
    sfClock_restart(player->reload);
    hud->showLoading = 0;
}

int check_switch_weapon(player_t *player, weapon_t **current_weapon,
items_t *selected, hud_t *hud)
{
    if (!AMMOCONTAINER(selected->weapon->ammoType)) {
        reset_reloading(player, current_weapon, hud);
        return (1);
    }
    if (!(*current_weapon)) {
        *current_weapon = selected->weapon;
        sfClock_restart(player->reload);
        hud->showLoading = 1;
        return (0);
    }
    if (*current_weapon != selected->weapon) {
        reset_reloading(player, current_weapon, hud);
        return (1);
    }
    return (0);
}

void reload_weapon(hud_t *hud, player_t *player)
{
    static weapon_t *current_weapon = NULL;
    items_t *selected = player->equipedItems->slots
    [player->equipedItems->currentSeclectedItem];

    if (!selected || !selected->weapon || !player->state->isReloading ||
    selected->weapon->magazine == selected->weapon->maxAmmo) {
        player->state->isReloading = 0;
        return;
    }
    if (check_switch_weapon(player, &current_weapon, selected, hud))
        return;
    if (sfTime_asSeconds(sfClock_getElapsedTime(player->reload)) <
    selected->weapon->reloadTime)
        return;
    while (selected->weapon->magazine < selected->weapon->maxAmmo &&
    AMMOCONTAINER(selected->weapon->ammoType) > 0) {
        selected->weapon->magazine += 1;
        AMMOCONTAINER(selected->weapon->ammoType) -= 1;
    }
    reset_reloading(player, &current_weapon, hud);
}
