/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** How to play menu
*/

#include"my_rpg.h"

void button_how_to_play(sfVector2f mode, main_t *main)
{
    build_button(&main->buttons, "srpfl", HTP_MENU, BUTTON_SPRITE[LEFT_HOW],
    (sfVector2f){1650 * mode.x, 850 * mode.y},
    (sfVector2f){0.7 * mode.x, 0.7 * mode.y}, &pass_next_scene);
    build_button(&main->buttons, "srpfl", HTP_MENU, BUTTON_SPRITE[RIGHT_HOW],
    (sfVector2f){300 * mode.x, 850 * mode.y},
    (sfVector2f){0.7 * mode.x, 0.7 * mode.y}, &pass_prev_scene);
    build_button(&main->buttons, "srpfl", HTP_MENU,
    BUTTON_SPRITE[QUIT_INVENTORY], (sfVector2f){220 * mode.x, 150 * mode.y},
    (sfVector2f){0.7 * mode.x, 0.7 * mode.y}, &goto_menu);
}

void pass_next_scene(main_t *main)
{
    if (main->howto->scene < 7)
        main->howto->scene++;
}

void pass_prev_scene(main_t *main)
{
    if (main->howto->scene > 0)
        main->howto->scene--;
}

void how_to_play_manager(main_t *main)
{
    sfVector2f mode = {(float)main->window->mode.width / 1920,
    (float)main->window->mode.height / 1080};

    sfRenderWindow_setView(main->window->screen, main->window->menuView);
    if (main->howto->scene <= 7 && main->howto->scene >= 0)
        sfSprite_setTextureRect(main->menu->htpMenu->sprite,
        HOW_TO_RECT[main->howto->scene]);
    sfSprite_setPosition(main->menu->htpMenu->sprite,
    (sfVector2f){125 * mode.x, 50 * mode.y});
    sfSprite_setScale(main->menu->htpMenu->sprite,
    (sfVector2f){1 * mode.x, 1 * mode.y});
    sfRenderWindow_drawSprite(main->window->screen,
    main->menu->htpMenu->sprite, 0);
    sfRenderWindow_setView(main->window->screen, main->window->gameView);
}
