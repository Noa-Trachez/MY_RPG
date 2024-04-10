/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Check for available textures
*/

#include "my_rpg.h"

int try_texture(char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    if (texture == NULL)
        return (1);
    sfTexture_destroy(texture);
    return (0);
}

int try_font(char *path)
{
    sfFont *font = sfFont_createFromFile(path);

    if (font == NULL)
        return (1);
    sfFont_destroy(font);
    return (0);
}

int check_assets(void)
{
    if (!get_font() || !get_interface() || !get_bkgrnd() || !get_npc() ||
        !get_objects() || !get_character() || !get_htp() || !get_music() ||
        !get_menu_music() || !get_sound_click() || !get_sound_achievement() ||
        try_font("assets/fonts/Oswald-Bold.ttf") ||
        try_texture("assets/inventory/inventory.png") || !get_cin() ||
        try_texture("assets/space_back/0.png") ||
        try_texture("assets/space_back/1.png") ||
        try_texture("assets/space_back/2.png"))
        return (1);
    return (0);
}
