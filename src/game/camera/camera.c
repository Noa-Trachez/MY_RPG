/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Ingame camera
*/

#include "my_rpg.h"

void ingame_zoom(main_t *main)
{
    static int zoom_ratio = 0;

    if (!main->game->player->state->canZoom)
        return;
    if (main->event.type != sfEvtMouseWheelScrolled) {
        sfRenderWindow_setView(main->window->screen, main->window->gameView);
        return;
    }
    if (main->event.mouseWheelScroll.delta < 0.0 && zoom_ratio < 2) {
        zoom_ratio += 1;
        sfView_zoom(main->window->gameView, (float)(1.0 / 1.1));
    } else if (main->event.mouseWheelScroll.delta > 0.0 && zoom_ratio > -8) {
        zoom_ratio -= 1;
        sfView_zoom(main->window->gameView, (float)1.1);
    }
    sfRenderWindow_setView(main->window->screen, main->window->gameView);
    get_goals(main, QU_ZOOM);
}
