/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Build an sfText
*/

#include "my_rpg.h"

sfText *create_text(const char *str, int size, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = get_font();
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    return text;
}
