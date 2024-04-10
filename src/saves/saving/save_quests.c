/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Quests saving
*/

#include "my_rpg.h"

void save_quests(game_t *game, int fd)
{
    quest_t *head = game->quest;

    while (head) {
        write(fd, &head->accomplish, sizeof(int));
        write(fd, &head->nb, sizeof(int));
        write(fd, &head->mandatory, sizeof(int));
        head = head->next;
    }
}
