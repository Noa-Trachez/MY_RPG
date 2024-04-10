/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** draw_life
*/

#include "my_rpg.h"

void resize_life(main_t *main)
{
    hud_t *hud = main->hud;
    player_t *player = main->game->player;
    sfVector2f mode = {(float)main->window->mode.width / 1920,
    (float)main->window->mode.height / 1080};

    if (main->game->player->currentHealth < 0)
        return;
    for (int i = 0; i < 2; i++)
        sfRectangleShape_setPosition(hud->life[i], (sfVector2f){50 * mode.x,
        1010 * mode.y});
    sfRectangleShape_setSize(hud->life[0],
    (sfVector2f){200 * mode.x, 30 * mode.y});
    sfRectangleShape_setSize(hud->life[1],
    (sfVector2f){player->currentHealth * 200 /
    player->stats->health * mode.x, 30 * mode.y});
}

void draw_life(main_t *main)
{
    hud_t *hud = main->hud;

    sfRenderWindow_setView(main->window->screen, main->window->menuView);
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawRectangleShape(main->window->screen, hud->life[i],
        0);
    resize_life(main);
    sfRenderWindow_setView(main->window->screen, main->window->gameView);
}
