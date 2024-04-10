/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Quests loading from save
*/

#include "my_rpg.h"

void load_quests(game_t *game, int fd)
{
    quest_t *head = game->quest;

    while (head) {
        read(fd, &head->accomplish, sizeof(int));
        read(fd, &head->nb, sizeof(int));
        read(fd, &head->mandatory, sizeof(int));
        head = head->next;
    }
}
