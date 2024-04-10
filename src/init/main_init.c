/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** INIT EVERYTHING
*/

#include "my_rpg.h"

void start_music(main_t *main)
{
    if (main->sound->muse) {
        sfMusic_setLoop(main->sound->muse, 1);
        sfMusic_setVolume(main->sound->muse, main->window->sound);
    }
    if (main->sound->menu_music) {
        sfMusic_setLoop(main->sound->menu_music, 1);
        sfMusic_play(main->sound->menu_music);
        sfMusic_setVolume(main->sound->menu_music, main->window->sound);
    }
}

void init_key_main(main_t *main)
{
    main->key_code = malloc(sizeof(keycode_t));
    main->key_code->up = sfKeyZ;
    main->key_code->down = sfKeyS;
    main->key_code->left = sfKeyQ;
    main->key_code->right = sfKeyD;
    main->key_code->inventory = sfKeyI;
    main->key_code->interact = sfKeyE;
    main->key_code->binding = NULL;
}

void game_struct_init(main_t *main)
{
    init_doors(main);
    init_life(main);
    menu_init(main);
    sound_init(main);
    init_chests(main);
    init_story(main);
    button_manager(main);
    player_init(main->game->player);
}

void game_init(main_t *main)
{
    srand((long)(&main));
    main->gameTick = sfClock_create();
    main->scene = 0;
    init_key_main(main);
    init_window(main);
    malloc_structs(main);
    init_npc(main);
    init_quests(main);
    init_cinematic(main);
    init_tp(main);
    game_struct_init(main);
}
