/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Main NPCs checks
*/

#include "my_rpg.h"

int pass(main_t *main, npc_t *npc)
{
    int current_npc = get_current_npc(main);

    if (current_npc == -1)
        return (0);
    if (!DISCUSS[current_npc][npc->selector][npc->index + 1])
        return (1);
    return (0);
}

int check_object(main_t *main, __attribute__((unused))npc_t *npc,
const int args[2])
{
    items_t *head = main->game->player->inventory;

    while (head && head->id != args[0])
        head = head->next;
    if (head && head->object && head->object->count >= args[1])
        return 1;
    if (head && head->id == args[0] && args[1] == -1)
        return 1;
    return 0;
}

int check_quest_complete(main_t *main,  __attribute__((unused))npc_t *npc,
const int args[2])
{
    quest_t *head = main->game->quest;

    while (head) {
        if (head->type == args[0] && head->accomplish)
            return 1;
        head = head->next;
    }
    return 0;
}
