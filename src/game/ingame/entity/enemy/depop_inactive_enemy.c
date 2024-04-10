/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Depop enemy after x seconds
*/

#include "my_rpg.h"

void depop_enemy(enemies_t *enemies)
{
    enemies_t *head = enemies;

    while (head) {
        if (head->id == BOSS ||
        sfTime_asSeconds(sfClock_getElapsedTime(head->clock)) < 60) {
            head = head->next;
            continue;
        }
        if (head->items) {
            free(head->items->weapon);
            free(head->items->object);
            free(head->items->ammo);
            free(head->items);
            head->items = NULL;
        }
        head->toBeDestroyed = 1;
        head = head->next;
    }
}
