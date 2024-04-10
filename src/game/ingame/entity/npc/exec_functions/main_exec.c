/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Main NPCs Execution
*/

#include "my_rpg.h"

int toggle_tp(main_t *main, int args)
{
    main->game->tp[args]->activate = !main->game->tp[args]->activate;
    return (0);
}

int depop_inventory(main_t *main, int id)
{
    items_t *head = main->game->player->inventory;

    while (head) {
        if (head->id == id) {
            unequip_item(main->game->player->equipedItems, head);
            destroy_item(&main->game->player->inventory, head);
            return (0);
        }
        head = head->next;
    }
    return (0);
}

int launch_end(main_t *main)
{
    main->hud->fadeState = 1;
    main->game->story->fadeColor = 0;
    return 0;
}

int continue_discuss(main_t *main, __attribute__((unused))int args,
npc_t *npc)
{
    int current_npc = get_current_npc(main);

    if (current_npc == -1)
        return (0);
    if (DISCUSS[current_npc][npc->selector + 1][0] &&
        npc->selector < npc->total)
        npc->selector++;
    return (0);
}
