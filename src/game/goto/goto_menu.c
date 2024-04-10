/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Goto main menu
*/

#include "my_rpg.h"

void rescale_sprite_when_go_pause_menu(main_t *main)
{
    sfVector2u tmp = sfTexture_getSize(main->pause_menu->screen);
    sfVector2f scale = {(float)main->window->size.x,
    (float)main->window->size.y};

    scale.x /= (float)tmp.x;
    scale.y /= (float)tmp.y;
    sfSprite_setScale(main->pause_menu->background, scale);
    sfRectangleShape_setScale(main->pause_menu->layer, scale);
}

static void destroy_menus(main_t *main)
{
    if (main->pause_menu) {
        main->pause_menu->pause = 0;
        destroy_pause_menu(main);
    }
    if (main->menu && main->menu->loadMenu)
        destroy_load_menu(main->menu, main->saves);
    if (main->game)
        reload_game(main->game);
}

void goto_menu(main_t *main)
{
    if (main->menu->htpMenu)
        destroy_htp_menu(main);
    if (main->pause_menu && main->pause_menu->pause == 1 &&
        main->scene != PAUSE_MENU) {
        rescale_sprite_when_go_pause_menu(main);
        main->scene = PAUSE_MENU;
    } else {
        destroy_menus(main);
        sfView_destroy(main->window->menuView);
        sfView_destroy(main->window->gameView);
        main->window->menuView =
        sfView_copy(sfRenderWindow_getDefaultView(main->window->screen));
        main->window->gameView = sfView_copy(main->window->menuView);
        main->scene = MAIN_MENU;
        sfMusic_stop(main->sound->muse);
        sfMusic_play(main->sound->menu_music);
    }
}
