/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** global_sound
*/

#include "my_rpg.h"

sfSoundBuffer *get_sound_click(void)
{
    static sfSoundBuffer *sheet = NULL;

    if (sheet == NULL)
        sheet = sfSoundBuffer_createFromFile("assets/sound/click.ogg");
    return (sheet);
}

sfSoundBuffer *get_sound_achievement(void)
{
    static sfSoundBuffer *sheet = NULL;

    if (sheet == NULL)
        sheet = sfSoundBuffer_createFromFile("assets/sound/achievement.ogg");
    return (sheet);
}

sfMusic *get_music(void)
{
    static sfMusic *sound = NULL;

    if (sound == NULL)
        sound = sfMusic_createFromFile("assets/sound/music.ogg");
    return (sound);
}

sfMusic *get_menu_music(void)
{
    static sfMusic *sound = NULL;

    if (sound == NULL)
        sound = sfMusic_createFromFile("assets/sound/menu_music.ogg");
    return (sound);
}
