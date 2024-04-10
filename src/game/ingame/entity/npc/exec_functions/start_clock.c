/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** start_clock
*/

#include "my_rpg.h"

int start_clock(__attribute((unused))main_t *main,
__attribute((unused))int args, npc_t *npc)
{
    npc->clock = sfClock_create();
    return 0;
}
