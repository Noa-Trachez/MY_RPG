/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Sound manager
*/

#include "my_rpg.h"

void volume_down(main_t *main)
{
    char *str;

    if (main->window->sound > 0) {
        main->window->sound -= 10;
        str = int_to_str(main->window->sound);
        str = my_strappend(str, " %", 1);
        sfText_setString(main->menu->msg, str);
        free(str);
    }
    if (main->sound->muse)
        sfMusic_setVolume(main->sound->muse, main->window->sound);
    if (main->sound->menu_music)
        sfMusic_setVolume(main->sound->menu_music, main->window->sound);
    if (main->sound->on_click)
        sfSound_setVolume(main->sound->on_click, main->window->sound);
    if (main->sound->achievement)
        sfSound_setVolume(main->sound->achievement, main->window->sound);
}

void volume_up(main_t *main)
{
    char *str;

    if (main->window->sound < 100) {
        main->window->sound += 10;
        str = int_to_str(main->window->sound);
        str = my_strappend(str, " %", 1);
        sfText_setString(main->menu->msg, str);
        free(str);
    }
    if (main->sound->muse)
        sfMusic_setVolume(main->sound->muse, main->window->sound);
    if (main->sound->menu_music)
        sfMusic_setVolume(main->sound->menu_music, main->window->sound);
    if (main->sound->on_click)
        sfSound_setVolume(main->sound->on_click, main->window->sound);
    if (main->sound->achievement)
        sfSound_setVolume(main->sound->achievement, main->window->sound);
}

void destroy_sound(main_t *main)
{
    if (main->sound->muse) {
        sfMusic_stop(main->sound->muse);
        sfMusic_stop(main->sound->menu_music);
        sfMusic_destroy(main->sound->muse);
        sfMusic_destroy(main->sound->menu_music);
    }
    if (main->sound->on_click) {
        sfSound_stop(main->sound->on_click);
        sfSound_destroy(main->sound->on_click);
        sfSoundBuffer_destroy(main->sound->buff);
    }
    if (main->sound->achievement) {
        sfSound_stop(main->sound->achievement);
        sfSound_destroy(main->sound->achievement);
        sfSoundBuffer_destroy(main->sound->buff_achievement);
    }
}
