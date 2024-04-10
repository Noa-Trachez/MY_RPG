/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Destroy enemy
*/

#include "my_rpg.h"

void destroy_enemy_id(main_t *main, int type)
{
    enemies_t *head = main->enemies;

    while (head) {
        if (head->items->id == type)
            head->toBeDestroyed = NO_DROP;
        head = head->next;
    }
}
