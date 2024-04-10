/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Update quests
*/

#include "my_rpg.h"

void change_quest(main_t *main, quest_t *quest)
{
    if (quest->nb >= quest->total && !quest->accomplish) {
        quest->accomplish = 1;
        add_quest_popup(&main->hud->questHud,
        my_strappend("Quest Finished :\t",
        (char *)sfText_getString(quest->text), 0));
        if (quest->item[0] != UNUSED)
            drop_item(&quest->getItem, &main->game->onGroundItems,
            main->game->player->pos, main->game->map->currentMap);
        if (quest->prev && quest->prev->mandatory == 1)
            quest->prev->mandatory = 0;
    }
}

int get_goals(main_t *main, int type)
{
    quest_t *quest = main->game->quest;

    if (type == -1)
        return (0);
    for (; quest; quest = quest->next) {
        if (quest->type == type && quest->accomplish == 0 &&
        quest->mandatory == 0)
            quest->nb += 1;
        change_quest(main, quest);
    }
    return (0);
}
