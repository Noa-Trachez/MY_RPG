/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Player loading from save
*/

#include "my_rpg.h"

void load_player(game_t *game, int fd)
{
    player_t *player = game->player;

    read(fd, &player->currentHealth, sizeof(int));
    read(fd, &player->pos, sizeof(sfVector2f));
    read(fd, player->stats, sizeof(stats_t));
    read(fd, player->state, sizeof(playerState_t));
    read(fd, player->ammo, sizeof(ammoContainer_t));
    load_items(game, fd);
}
