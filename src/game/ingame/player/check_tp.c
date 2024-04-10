/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Check player position for tp-ing
*/

#include "my_rpg.h"

void check_tp(game_t *game, player_t *player, sfIntRect player_rect,
map_t *map)
{
    for (int i = 0; ALL_TP[i].activate != END; i++) {
        if (game->tp[i] && game->tp[i]->activate &&
        sfIntRect_intersects(&player_rect,
        &game->tp[i]->rect, NULL) && map->currentMap == game->tp[i]->actual) {
            switch_map(map, game, game->tp[i]->go_to);
            player->pos = game->tp[i]->spawn;
            sfRectangleShape_setPosition(player->sprite, player->pos);
            return;
        }
    }
}
