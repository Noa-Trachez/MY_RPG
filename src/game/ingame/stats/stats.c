/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Stats display
*/

#include "my_rpg.h"

void bar_display(main_t *main, sfRectangleShape **rect, sfVector2f mode)
{
    sfRectangleShape_setPosition(rect[0], (sfVector2f){268 * mode.x,
    281 * mode.y});
    sfRectangleShape_setScale(rect[0], (sfVector2f){1 * mode.x, 1 * mode.y});
    sfRectangleShape_setSize(rect[0],
    (sfVector2f){(1393 *((float)main->game->player->stats->health / 100))
    , 34});
    sfRectangleShape_setFillColor(rect[0], sfRed);
    sfRectangleShape_setPosition(rect[1], (sfVector2f){268 * mode.x,
    482 * mode.y});
    sfRectangleShape_setScale(rect[1], (sfVector2f){1 * mode.x, 1 * mode.y});
    sfRectangleShape_setSize(rect[1],
    (sfVector2f){(1393 *((float)main->game->player->stats->level / 100))
    , 34});
    sfRectangleShape_setFillColor(rect[1], (sfColor){3, 255, 102, 255});
}

void draw_all_stat(sfRenderWindow *screen, sfText *info, stats_t *stat,
sfVector2f mode)
{
    char *str = NULL;
    int stats[6] = {stat->speed, stat->luck, stat->damage, stat->endurance,
    stat->resistance, stat->attackSpeed};
    int posx = 650;
    int posy = 630;

    for (int i = 0; i < 6; i++) {
        str = int_to_str(stats[i]);
        sfText_setString(info, str);
        free(str);
        sfText_setPosition(info, (sfVector2f){posx * mode.x, posy * mode.y});
        sfRenderWindow_drawText(screen, info, 0);
        posy += 100;
        if (i == 2) {
            posx = 1450;
            posy = 630;
        }
    }
}

void resize_stats_manager(main_t *main, sfSprite *sprite, sfText *info,
sfRectangleShape **rect)
{
    sfVector2f mode = {(float)main->window->mode.width / 1920,
    (float)main->window->mode.height / 1080};

    sfSprite_setScale(sprite, (sfVector2f){mode.x * 1.35, mode.y * 1.3});
    sfSprite_setPosition(sprite, (sfVector2f){60 * mode.x, 50 * mode.y});
    sfRenderWindow_drawSprite(main->window->screen, sprite, 0);
    sfText_setCharacterSize(info, 40 * mode.x);
    bar_display(main, rect, mode);
    draw_all_stat(main->window->screen, info, main->game->player->stats, mode);
    sfRenderWindow_drawRectangleShape(main->window->screen, rect[0], 0);
    sfRenderWindow_drawRectangleShape(main->window->screen, rect[1], 0);
}

void stat_manager(main_t *main)
{
    static sfSprite *sprite = NULL;
    static sfText *info = NULL;
    static sfRectangleShape *rect[2];

    if (main->game->player->state->inStats == 0)
        return;
    if (!sprite) {
        sprite = sfSprite_create();
        info = create_text("Info", 40, (sfVector2f){600, 500});
        sfSprite_setTexture(sprite, get_interface(), sfTrue);
        sfSprite_setTextureRect(sprite, INTERFACE_SPRITE[IN_HUD]);
    }
    rect[0] = sfRectangleShape_create();
    rect[1] = sfRectangleShape_create();
    sfRenderWindow_setView(main->window->screen, main->window->menuView);
    resize_stats_manager(main, sprite, info, rect);
    sfRenderWindow_setView(main->window->screen, main->window->gameView);
}
