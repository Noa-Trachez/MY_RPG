/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Global textures 2
*/

#include "my_rpg.h"

sfTexture *get_objects(void)
{
    static sfTexture *sheet = NULL;

    if (sheet == NULL)
        sheet = sfTexture_createFromFile("assets/objects.png", 0);
    return (sheet);
}

sfTexture *get_character(void)
{
    static sfTexture *sheet = NULL;

    if (sheet == NULL)
        sheet = sfTexture_createFromFile("assets/game/characters.png", 0);
    return (sheet);
}

sfTexture *get_htp(void)
{
    static sfTexture *sheet = NULL;

    if (sheet == NULL)
        sheet = sfTexture_createFromFile("assets/how_to_play.png", 0);
    return (sheet);
}

sfTexture *get_cin(void)
{
    static sfTexture *sheet = NULL;

    if (sheet == NULL)
        sheet = sfTexture_createFromFile("assets/cin.png", 0);
    return (sheet);
}
