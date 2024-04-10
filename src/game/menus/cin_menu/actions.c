/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Cinematic actions
*/

#include "my_rpg.h"

void shake_map(sfSprite *sprite, main_t * main)
{
    if (sfTime_asSeconds(
    sfClock_getElapsedTime(main->cinematic->map_clock)) > 0.020) {
        sfSprite_setPosition(sprite, (sfVector2f)
        {(sfSprite_getPosition(sprite).x - 10) * -1,
        (sfSprite_getPosition(sprite).y + 10) * -1});
        sfClock_restart(main->cinematic->map_clock);
    }
}

void anim_planet(main_t *main)
{
    sfVector2f mode = {(float)main->window->mode.width / 1920,
    (float)main->window->mode.height / 1080};

    if (sfTime_asSeconds(
    sfClock_getElapsedTime(main->cinematic->next_clock)) > 3)
        return;
    if (sfTime_asSeconds(
    sfClock_getElapsedTime(main->cinematic->anim_clock)) > 0.02) {
        sfSprite_setPosition(main->cinematic->image, (sfVector2f){
        sfSprite_getPosition(main->cinematic->image).x - 8,
        500 * mode.y});
        sfClock_restart(main->cinematic->anim_clock);
    }
}

void pass_next(main_t *main)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(main->cinematic->next_clock))
    > 5 || main->cinematic->go_next == 1) {
        if (main->cinematic->prev != NULL)
            main->cinematic = main->cinematic->prev;
        else {
            main->game->player->state->canZoom = 1;
            main->game->story->isStoryDone = 0;
            main->cin = 0;
        }
    }
}

void draw_front_view(main_t *main)
{
    sfVector2f mode = {(float)main->window->mode.width / 1920,
    (float)main->window->mode.height / 1080};

    back_space_display(main);
    sfRenderWindow_drawText(main->window->screen,
    main->cinematic->subtitle, 0);
    if (main->cinematic->scene == 4)
        sfSprite_setScale(main->cinematic->image, (sfVector2f){
        mode.x * 0.7, mode.y * 0.7});
    if (main->cinematic->scene != 3)
        sfRenderWindow_drawSprite(main->window->screen,
        main->cinematic->image, 0);
    else
        sfRenderWindow_drawSprite(main->window->screen,
        main->cinematic->planet, 0);
}

void crash_ship(main_t *main)
{
    if (main->cinematic->scene == 4) {
        sfSprite_setRotation(main->cinematic->image, 180);
        anim_planet(main);
        sfRenderWindow_drawSprite(main->window->screen,
        main->game->map->map, 0);
    }
}
