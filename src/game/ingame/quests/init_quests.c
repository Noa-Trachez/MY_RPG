/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** INIT quests
*/

#include "my_rpg.h"

void init_quests(main_t *main)
{
    quest_t *quest = NULL;

    main->hud->questHud = NULL;
    main->game->quest = NULL;
    for (int i = 0; TAB_QUESTS[i].str; i++) {
        main->game->quest = new_quest(main->game->quest, TAB_QUESTS[i]);
        if (i == 0)
            quest = main->game->quest;
    }
    main->game->quest = quest;
}
