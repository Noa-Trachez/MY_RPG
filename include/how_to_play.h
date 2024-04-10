/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** HTP.h
*/

#ifndef HOW_TO
    #define HOW_TO

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>

static const sfIntRect HOW_TO_RECT[10] = {
    {0, 0, 1689, 940},
    {1690, 0, 1690, 941},
    {0, 941, 1690, 941},
    {1690, 941, 1690, 941},
    {0,1882, 1690, 941},
    {1690, 1882, 1690, 941},
    {0, 2823, 1690, 941},
    {1690, 2823, 1690, 941},
    {0, 3762, 145, 145},
    {200, 3765, 145, 145},
};

typedef struct howto_s {
    int scene;
} howto_t;
#endif/*HOW_TO*/
