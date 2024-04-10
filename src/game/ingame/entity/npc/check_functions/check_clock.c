/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Check clock
*/

#include "my_rpg.h"

int check_clock(__attribute__((unused))main_t *main, npc_t *npc,
const int args[2])
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(npc->clock)) > args[0])
        return 1;
    return 0;
}
