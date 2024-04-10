/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** INIT settings
*/

#include "my_rpg.h"

void init_text_and_fonts(main_t *main)
{
    main->menu->msg = sfText_create();
    main->menu->fonts = sfFont_createFromFile("assets/fonts/Oswald-Bold.ttf");
    sfText_setColor(main->menu->msg, sfBlack);
    sfText_setCharacterSize(main->menu->msg, 50);
    sfFloatRect coucou = sfText_getGlobalBounds(main->menu->msg);
    sfText_setOrigin(main->menu->msg,
    (sfVector2f){coucou.width / 2, coucou.height / 2});
    sfText_setFont(main->menu->msg, main->menu->fonts);
    sfText_setPosition(main->menu->msg, (sfVector2f){main->window->mode.width
    / 2.8, main->window->mode.height / 1.85});
    sfText_setString(main->menu->msg,
    my_strappend(int_to_str(main->window->sound), " %", 1));
}

void menu_init(main_t *main)
{
    main->menu->background = sfSprite_create();
    sfSprite_setTexture(main->menu->background, get_bkgrnd(), 0);
    init_text_and_fonts(main);
    if (main->window->mode.width == 1920) {
        sfSprite_setScale(main->menu->background, (sfVector2f){3.4, 3.4});
        sfText_setCharacterSize(main->menu->msg, 100);
    } else if (main->window->mode.width == 1066) {
        sfSprite_setScale(main->menu->background, (sfVector2f){1.88, 1.88});
        sfText_setCharacterSize(main->menu->msg, 50);
    } else {
        sfSprite_setScale(main->menu->background, (sfVector2f){4.5, 4.5});
        sfText_setCharacterSize(main->menu->msg, 150);
    }
    main->menu->loadMenu = NULL;
}
