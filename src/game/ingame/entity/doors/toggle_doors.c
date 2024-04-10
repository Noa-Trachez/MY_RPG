/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Toggle doors
*/

#include "my_rpg.h"

int toggle_doors(main_t *main, int id)
{
    door_t *head = main->game->doors;

    while (head) {
        if (head->id == id)
            head->activate = !head->activate;
        head = head->next;
    }
    return (0);
}
