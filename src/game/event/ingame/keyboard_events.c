/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Ingame keyboard events
*/

#include "my_rpg.h"

void get_keys_pressed(main_t *main)
{
    if (main->event.type == sfEvtKeyPressed &&
        main->event.key.code == main->key_code->interact)
        handle_npc(main, main->game->player);
    if (main->event.type == sfEvtKeyPressed &&
        main->event.key.code == sfKeyEscape)
        goto_pause(main);
    if (main->event.type == sfEvtKeyPressed &&
        main->event.key.code == sfKeyC) {
        get_goals(main, QU_QUEST);
        main->game->player->state->inStats =
        !main->game->player->state->inStats;
        main->game->player->state->inInventory = 0;
        main->game->player->state->inQuests = 0;
    }
}

void ingame_menu_keys(main_t *main)
{
    if (main->event.type == sfEvtKeyPressed &&
    main->event.key.code == sfKeyTab) {
        get_goals(main, QU_INVENTORY);
        main->game->player->state->inInventory =
        !main->game->player->state->inInventory;
        main->game->player->state->inQuests = 0;
        main->game->player->state->inStats = 0;
    }
    if (main->event.type == sfEvtKeyPressed &&
    main->event.key.code == main->key_code->inventory) {
        get_goals(main, QU_QUEST);
        main->game->player->state->inQuests =
        !main->game->player->state->inQuests;
        main->game->player->state->inInventory = 0;
        main->game->player->state->inStats = 0;
    }
}

void select_item(main_t *main)
{
    if (!main->game->player->state->inQuests &&
        !main->game->player->state->inInventory) {
        if (sfKeyboard_isKeyPressed(sfKeyNum1))
            main->game->player->equipedItems->currentSeclectedItem = 0;
        if (sfKeyboard_isKeyPressed(sfKeyNum2))
            main->game->player->equipedItems->currentSeclectedItem = 1;
        if (sfKeyboard_isKeyPressed(sfKeyNum3))
            main->game->player->equipedItems->currentSeclectedItem = 2;
        if (sfKeyboard_isKeyPressed(sfKeyNum4))
            main->game->player->equipedItems->currentSeclectedItem = 3;
    }
}

void ingame_interactions(main_t *main)
{
    if (main->event.type == sfEvtKeyPressed &&
    main->event.key.code == main->key_code->interact)
        player_interact(main, main->game->player, main->game->chest,
        &main->game->onGroundItems);
    if (main->event.type == sfEvtKeyPressed &&
    main->event.key.code == sfKeyR)
        main->game->player->state->isReloading = 1;
    select_item(main);
    get_keys_pressed(main);
    ingame_menu_keys(main);
}
