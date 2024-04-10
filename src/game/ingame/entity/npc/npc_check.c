/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** NPCs check
*/

#include "my_rpg.h"

void npc_check(main_t *main, npc_t *npc, int i)
{
    int (*check[])() = {&pass, &check_object, &check_clock,
    &check_quest_complete};
    int (*exe[])() = {&continue_discuss, &get_goals, &start_clock,
    &toggle_tp, &toggle_doors, &drop_npc_weapon, &drop_npc_ammo,
    &depop_inventory, &launch_end};
    int selector = npc ? npc->selector : 0;

    if (!npc)
        return;
    if (check[ACTION[i].f_check[selector]]
    (main, npc, ACTION[i].args_check[selector]))
        for (int func = 0; ACTION[i].f_exe[selector][func] != -1; func++)
            exe[ACTION[i].f_exe[selector][func]]
            (main, ACTION[i].args_exe[selector][func], npc);
    if (!DISCUSS[i][selector][npc->index + 1]) {
        npc->index = -1;
        main->game->player->state->canShot = 1;
        main->game->player->state->canMove = 1;
    }
}
