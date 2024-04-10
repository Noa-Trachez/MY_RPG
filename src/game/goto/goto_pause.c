/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Goto pause menu
*/

#include "my_rpg.h"

void destroy_pause_menu(main_t *main)
{
    sfTexture_destroy(main->pause_menu->screen);
    sfSprite_destroy(main->pause_menu->background);
    sfRectangleShape_destroy(main->pause_menu->layer);
    free(main->pause_menu);
    main->pause_menu = NULL;
}

void goto_pause(main_t *main)
{
    main->pause_menu = malloc(sizeof(pause_menu_t));
    main->pause_menu->pause = 1;
    main->pause_menu->screen = sfTexture_create(main->window->mode.width,
    main->window->mode.height);
    sfRenderWindow_display(main->window->screen);
    sfTexture_updateFromRenderWindow(main->pause_menu->screen,
    main->window->screen, 0, 0);
    main->pause_menu->background = sfSprite_create();
    sfSprite_setTexture(main->pause_menu->background,
    main->pause_menu->screen, sfFalse);
    main->pause_menu->layer = sfRectangleShape_create();
    sfRectangleShape_setSize(main->pause_menu->layer,
    (sfVector2f){main->window->size.x, main->window->size.y});
    sfRectangleShape_setFillColor(main->pause_menu->layer,
    (sfColor){0, 0, 0, 150});
    sfRenderWindow_setView(main->window->screen, main->window->menuView);
    main->scene = PAUSE_MENU;
    save_game(main->game);
}
