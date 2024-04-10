/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** cinematic
*/

#ifndef CINEMATIC_H
    #define CINEMATIC_H

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>

typedef struct cinematic_s {
    sfText *subtitle;
    sfSprite *image;
    sfSprite *planet;
    sfClock *next_clock;
    sfClock *anim_clock;
    sfClock *map_clock;
    int go_next;
    int start;
    int scene;
    struct cinematic_s *next;
    struct cinematic_s *prev;
} cinematic_t;

__attribute((unused))static const char *SUB[7] =
{
    "This is the beginning of my adventure.",
    "I was walking around on my ship.",
    "That's when my ship caught fire.",
    "I'm going to make an emergency landing on this planet",
    " ",
    NULL
};

static const sfIntRect RECT_CIN[2] = {
    {0, 110, 1181, 640},
    {0, 0, 100, 98},
};

#endif/*CINEMATIC_H*/
