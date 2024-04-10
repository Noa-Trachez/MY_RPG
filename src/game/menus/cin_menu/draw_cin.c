/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Cinematic display
*/

#include "my_rpg.h"

void resize_cin(main_t *main, sfVector2f mode)
{
    if (main->cinematic->scene == 3) {
        sfSprite_setPosition(main->cinematic->planet, (sfVector2f){
        mode.x * 800, mode.y * 500});
        sfSprite_setScale(main->cinematic->planet, (sfVector2f){
        mode.x * 2, mode.y * 2});
    } else if (main->cinematic->scene != 4) {
        sfSprite_setPosition(main->cinematic->image, (sfVector2f){
        mode.x * 800, mode.y * 500});
        sfSprite_setScale(main->cinematic->image, (sfVector2f){
        mode.x * 0.7, mode.y * 0.7});
    }
    sfText_setPosition(main->cinematic->subtitle, (sfVector2f){
    mode.x * 750, mode.y * 800});
    sfText_setCharacterSize(main->cinematic->subtitle, mode.x * 30);
    for (int i = 0; i < 3; i++)
        sfSprite_setScale(main->background[i], (sfVector2f){mode.x, mode.y});
}

void back_space_display(main_t *main)
{
    if (main->cinematic->scene != 4) {
        for (int i = 0; i < 3; i++)
            sfRenderWindow_drawSprite(main->window->screen,
            main->background[i], 0);
    }
}

void move_sprite(sfSprite *sprite, main_t *main)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(main->clock_cin)) > 0.02) {
        sfIntRect pos = sfSprite_getTextureRect(sprite);
        pos.left += 3;
        sfSprite_setTextureRect(sprite, pos);
        pos = sfSprite_getTextureRect(main->background[2]);
        pos.left += 5;
        sfSprite_setTextureRect(main->background[2], pos);
        sfClock_restart(main->clock_cin);
    }
}

void cinematic_menu(main_t *main)
{
    sfVector2f mode = {(float)main->window->mode.width / 1920,
    (float)main->window->mode.height / 1080};
    resize_cin(main, mode);
    sfRenderWindow_setView(main->window->screen,
    main->window->gameView);
    crash_ship(main);
    move_sprite(main->background[1], main);
    sfRenderWindow_setView(main->window->screen,
    main->window->menuView);
    draw_front_view(main);
    sfRenderWindow_setView(main->window->screen,
    main->window->gameView);
    if (main->cinematic->start == 1) {
        sfClock_restart(main->cinematic->next_clock);
        main->cinematic->start = 0;
    }
    pass_next(main);
}
