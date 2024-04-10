/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Fullscreen manager
*/

#include "my_rpg.h"

void change_bkg(main_t *main)
{
    if (main->window->mode.width == 2560) {
        sfSprite_setTexture(main->menu->background, get_bkgrnd(), 0);
        sfSprite_setScale(main->menu->background, (sfVector2f){4.5, 4.5});
        sfText_setCharacterSize(main->menu->msg, 150);
    } else if (main->window->mode.width == 1920) {
        sfSprite_setTexture(main->menu->background, get_bkgrnd(), 0);
        sfSprite_setScale(main->menu->background, (sfVector2f){3.4, 3.4});
        sfText_setCharacterSize(main->menu->msg, 100);
    } else {
        sfSprite_setTexture(main->menu->background, get_bkgrnd(), 0);
        sfSprite_setScale(main->menu->background, (sfVector2f){1.88, 1.88});
        sfText_setCharacterSize(main->menu->msg, 50);
    }
}

void full_screen(main_t *main)
{
    sfVector2u size;
    size_t tmp;
    const sfVideoMode *modes = sfVideoMode_getFullscreenModes(&tmp);

    sfRenderWindow_close(main->window->screen);
    sfRenderWindow_destroy(main->window->screen);
    main->window->mode = modes[0];
    if (main->window->fullscreen == 0) {
        main->window->screen = sfRenderWindow_create(main->window->mode,
        "My RPG", sfFullscreen, NULL);
        main->window->fullscreen = 1;
    } else {
        main->window->screen = sfRenderWindow_create(main->window->mode,
        "My RPG", sfClose, NULL);
        main->window->fullscreen = 0;
    }
    size = sfRenderWindow_getSize(main->window->screen);
    main->window->size = (sfVector2i){size.x, size.y};
    change_bkg(main);
    continue_change_resolution(main, 0);
}
