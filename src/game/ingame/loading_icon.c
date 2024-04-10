/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Loading icon
*/

#include "my_rpg.h"

void init_loading_icon(hud_t *hud)
{
    sfColor colors[3] = {{255, 255, 255, 255}, {255, 255, 255, 210},
    {255, 255, 255, 170}};

    for (int i = 0; i < 3; i++) {
        if (!hud->loadingCircle[i]) {
            hud->loadingCircle[i] = sfCircleShape_create();
            sfCircleShape_setOrigin(hud->loadingCircle[i],
            (sfVector2f){-9, 2});
            sfCircleShape_setRadius(hud->loadingCircle[i], 2);
            sfCircleShape_setFillColor(hud->loadingCircle[i], colors[i]);
            sfCircleShape_setRotation(hud->loadingCircle[i], -30 * i);
        }
    }
}

void set_loading_icon_values(hud_t *hud, window_t *window)
{
    sfCircleShape_setPosition(hud->loadingCircle[0],
    (sfVector2f){window->mode.width / 2, window->mode.height / 2 - 50});
    sfCircleShape_setPosition(hud->loadingCircle[1],
    (sfVector2f){window->mode.width / 2, window->mode.height / 2 - 50});
    sfCircleShape_setPosition(hud->loadingCircle[2],
    (sfVector2f){window->mode.width / 2, window->mode.height / 2 - 50});
    sfCircleShape_rotate(hud->loadingCircle[0], 10);
    sfCircleShape_rotate(hud->loadingCircle[1], 10);
    sfCircleShape_rotate(hud->loadingCircle[2], 10);
}

void loading_icon(main_t *main)
{
    hud_t *hud = main->hud;
    window_t *window = main->window;

    init_loading_icon(hud);
    sfRenderWindow_setView(window->screen, window->menuView);
    set_loading_icon_values(hud, window);
    sfRenderWindow_drawCircleShape(window->screen, hud->loadingCircle[0], 0);
    sfRenderWindow_drawCircleShape(window->screen, hud->loadingCircle[1], 0);
    sfRenderWindow_drawCircleShape(window->screen, hud->loadingCircle[2], 0);
    sfRenderWindow_setView(window->screen, window->gameView);
}
