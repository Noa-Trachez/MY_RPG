/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Global textures 1
*/

#include "my_rpg.h"

sfFont *get_font(void)
{
    static sfFont *sheet = NULL;

    if (sheet == NULL)
        sheet = sfFont_createFromFile("assets/fonts/futur.ttf");
    return (sheet);
}

sfTexture *get_interface(void)
{
    static sfTexture *sheet = NULL;

    if (sheet == NULL)
        sheet = sfTexture_createFromFile("assets/menus/interface.png", 0);
    return (sheet);
}

sfTexture *get_npc(void)
{
    static sfTexture *sheet = NULL;

    if (sheet == NULL)
        sheet = sfTexture_createFromFile("assets/npc.png", 0);
    return (sheet);
}

sfTexture *get_bkgrnd(void)
{
    static sfTexture *sheet = NULL;

    if (sheet == NULL)
        sheet = sfTexture_createFromFile("assets/menus/backgrounds.png", 0);
    return (sheet);
}
