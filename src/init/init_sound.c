/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** init_sound
*/

#include "my_rpg.h"

void sound_init(main_t *main)
{
    main->sound = malloc(sizeof(sound_t));
    main->sound->buff = get_sound_click();
    main->sound->buff_achievement = get_sound_achievement();
    setup_sound(main);
    main->sound->muse = get_music();
    main->sound->menu_music = get_menu_music();
    start_music(main);
}

void setup_sound(main_t *main)
{
    if (main->sound->buff_achievement) {
        main->sound->achievement = sfSound_create();
        sfSound_setBuffer(main->sound->achievement,
        main->sound->buff_achievement);
        sfSound_setVolume(main->sound->achievement, main->window->sound);
    } else
        main->sound->achievement = NULL;
    if (main->sound->buff) {
        main->sound->on_click = sfSound_create();
        sfSound_setBuffer(main->sound->on_click, main->sound->buff);
        sfSound_setVolume(main->sound->on_click, main->window->sound);
    } else
        main->sound->on_click = NULL;
}
