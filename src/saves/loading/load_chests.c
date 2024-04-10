/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Chests loading from a save
*/

#include "my_rpg.h"

void load_chests(game_t *game, int fd)
{
    chest_t *head = game->chest;

    while (head) {
        read(fd, &head->isOpen, sizeof(int));
        head = head->next;
    }
}
