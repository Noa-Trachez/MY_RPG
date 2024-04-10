/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Chests saving
*/

#include "my_rpg.h"

void save_chests(game_t *game, int fd)
{
    chest_t *head = game->chest;

    while (head) {
        write(fd, &head->isOpen, sizeof(int));
        head = head->next;
    }
}
