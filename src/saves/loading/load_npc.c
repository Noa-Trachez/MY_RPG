/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** NPCs loading from save
*/

#include "my_rpg.h"

void load_npc(game_t *game, int fd)
{
    npc_t *head = game->npc;

    while (head) {
        read(fd, &head->selector, sizeof(int));
        head = head->next;
    }
}
