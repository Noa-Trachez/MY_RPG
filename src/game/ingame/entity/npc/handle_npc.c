/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** NPCs manager
*/

#include "my_rpg.h"

int get_current_npc(main_t *main)
{
    int i = 0;
    npc_t *save = main->game->npc;

    while (save) {
        if (save->isSelected == TALKING)
            return i;
        i++;
        save = save->next;
    }
    return (-1);
}

void change_message(main_t *main, player_t *player, npc_t *save, int i)
{
    int selector;
    sfVector2f player_rect = {player->pos.x, player->pos.y};
    sfVector2f npc_rect = {sfRectangleShape_getPosition(save->sprite).x,
    sfRectangleShape_getPosition(save->sprite).y};

    selector = save->selector;
    if (object_inrange(player_rect, npc_rect, 65) &&
    DISCUSS[i][selector] && DISCUSS[i][selector][save->index + 1]) {
        save->isSelected = TALKING;
        npc_check(main, save, i);
        save->index++;
        player->state->canShot = 0;
        player->state->canMove = 0;
    } else if (save->isSelected == TALKING && DISCUSS[i][selector] &&
    !DISCUSS[i][selector][save->index + 1]) {
        npc_check(main, save, i);
        save->isSelected = TALKED;
    }
}

void handle_npc(main_t *main, player_t *player)
{
    npc_t *save = main->game->npc;

    for (int i = 0; save; save = save->next, i++) {
        if (save->map != main->game->map->currentMap)
            continue;
        change_message(main, player, save, i);
    }
}
