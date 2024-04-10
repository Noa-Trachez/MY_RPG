/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Display in-game layers
*/

#include "my_rpg.h"

static sfRectangleShape *init_fade_screen(sfRectangleShape *rect)
{
    rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect, sfBlack);
    return (rect);
}

static void end_fade(main_t *main)
{
    story_t *story = main->game->story;

    if (story->fadeColor >= 255) {
        main->hud->fadeState = 0;
        main->game->story->fadeColor = 0;
        goto_menu(main);
    }
}

void fade_screen(main_t *main)
{
    static sfRectangleShape *rect = NULL;
    story_t *story = main->game->story;

    if (!rect)
        rect = init_fade_screen(rect);
    sfRenderWindow_setView(main->window->screen, main->window->menuView);
    sfRenderWindow_drawRectangleShape(main->window->screen, rect, 0);
    sfRenderWindow_setView(main->window->screen, main->window->gameView);
    if (sfTime_asSeconds(sfClock_getElapsedTime(story->clock)) < 0.1)
        return;
    sfRectangleShape_setSize(rect, (sfVector2f){main->window->mode.width,
    main->window->mode.height});
    sfRectangleShape_setFillColor(rect,
    sfColor_fromRGBA(0, 0, 0, story->fadeColor));
    story->fadeColor += 5;
    sfClock_restart(story->clock);
    end_fade(main);
}

void game_display(main_t *main, window_t *window)
{
    sfRenderWindow_drawSprite(main->window->screen, main->game->map->map, 0);
    doors_display(main);
    enemy_display(window, main->enemies, main->game->map->currentMap);
    display_items(main->game->map, main->game->onGroundItems, window->screen);
    projectile_display(main->game->player->projectiles, window);
    npc_display(main->game->npc, main->window, main->game->map->currentMap);
    player_display(main->game->player, main->window);
    chest_display(main->game->chest, window, main->game->map->currentMap);
    draw_life(main);
}
