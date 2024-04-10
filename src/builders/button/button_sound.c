/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Button sound on click
*/

#include "my_rpg.h"

void play_onclick_sound(main_t *main)
{
    sfSoundStatus status;

    if (!main->sound->on_click)
        return;
    status = sfSound_getStatus(main->sound->on_click);
    if (status != sfPlaying)
        sfSound_play(main->sound->on_click);
}
