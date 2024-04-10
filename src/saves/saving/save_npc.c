/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** NPCs saving
*/

#include "my_rpg.h"

void save_npc(game_t *game, int fd)
{
    npc_t *head = game->npc;

    while (head) {
        write(fd, &head->selector, sizeof(int));
        head = head->next;
    }
}
