/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Goto ingame scene
*/

#include "my_rpg.h"

void return_to_game(main_t *main)
{
    destroy_pause_menu(main);
    main->scene = INGAME;
}

void goto_ingame(main_t *main)
{
    if (main->menu->loadMenu) {
        load_game(main->game, main->menu->loadMenu->selectedSave);
        main->game->currentSave = main->menu->loadMenu->selectedSave;
        destroy_load_menu(main->menu, main->saves);
    }
    main->scene = INGAME;
    sfMusic_play(main->sound->muse);
    sfMusic_stop(main->sound->menu_music);
    sfRectangleShape_setPosition(main->game->player->sprite,
    main->game->player->pos);
    switch_map(main->game->map, main->game, main->game->map->currentMap);
    sfClock_restart(main->game->timePlayed);
}
