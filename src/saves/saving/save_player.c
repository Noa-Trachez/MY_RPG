/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Player saving
*/

#include "my_rpg.h"

void save_player(game_t *game, int fd)
{
    player_t *player = game->player;

    write(fd, &player->currentHealth, sizeof(int));
    write(fd, &player->pos, sizeof(sfVector2f));
    write(fd, player->stats, sizeof(stats_t));
    write(fd, player->state, sizeof(playerState_t));
    write(fd, player->ammo, sizeof(ammoContainer_t));
    save_item(game->player->inventory, fd);
}
