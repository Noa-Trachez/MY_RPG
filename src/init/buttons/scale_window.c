/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Rebuild and rescale buttons
*/

#include "my_rpg.h"

void scale_all_buttons(main_t *main, float size)
{
    buttons_t *head = main->buttons;

    while (main->buttons) {
        main->buttons->scale.x *= size;
        main->buttons->scale.y *= size;
        sfRectangleShape_setScale(main->buttons->sprite,
        (sfVector2f){main->buttons->scale.x, main->buttons->scale.y});
        sfRectangleShape_setPosition(main->buttons->sprite,
        main->buttons->pos);
        main->buttons = main->buttons->next;
    }
    main->buttons = head;
}

void continue_change_resolution(main_t *main, int needed)
{
    if (needed) {
        sfRenderWindow_destroy(main->window->screen);
        main->window->screen = sfRenderWindow_create(main->window->mode,
        "My RPG", sfClose, NULL);
    }
    sfView_destroy(main->window->gameView);
    sfView_destroy(main->window->menuView);
    main->window->gameView =
    sfView_copy(sfRenderWindow_getDefaultView(main->window->screen));
    main->window->menuView = sfView_copy(main->window->gameView);
    destroy_button(&main->buttons);
    button_manager(main);
    sfText_setPosition(main->menu->msg, (sfVector2f){main->window->mode.width
    / 2.25, main->window->mode.height / 1.7});
    sfRenderWindow_setFramerateLimit(main->window->screen, main->window->fps);
}

void change_scale_window(main_t *main)
{
    main->window->fullscreen = 0;
    if (main->window->mode.width == 1920) {
        main->window->mode = (sfVideoMode){2560, 1440, 32};
        main->window->size = (sfVector2i){2560, 1440};
    } else if (main->window->mode.width == 1066) {
        main->window->mode = (sfVideoMode){1920, 1080, 32};
        main->window->size = (sfVector2i){1920, 1080};
    } else {
        main->window->mode = (sfVideoMode){1066, 600, 32};
        main->window->size = (sfVector2i){1066, 600};
    }
    change_bkg(main);
    continue_change_resolution(main, 1);
}

void toggle_vsync(main_t *main)
{
    main->window->v_sync = !main->window->v_sync;
    main->window->v_sync ? change_sprite(main, BUTTON_SPRITE[VSINC_ON]) :
    change_sprite(main, BUTTON_SPRITE[VSINC_OFF]);
    sfRenderWindow_setVerticalSyncEnabled(main->window->screen,
    main->window->v_sync);
}

void change_fps(main_t *main)
{
    int tab[3] = {30, 60, 144};
    sfIntRect tab_rect[3] = {BUTTON_SPRITE[FPS_30], BUTTON_SPRITE[FPS_60],
    BUTTON_SPRITE[FPS_144]};
    int index;

    for (index = 0; index < 3; index++)
        if (main->window->fps == tab[index])
            break;
    index++;
    index = index == 3 ? 0 : index;
    main->window->fps = tab[index];
    change_sprite(main, tab_rect[index]);
    sfRenderWindow_setFramerateLimit(main->window->screen, main->window->fps);
}
