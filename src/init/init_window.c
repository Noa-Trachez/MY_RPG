/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** INIT Window struct
*/

#include "my_rpg.h"

void init_spec_windows(main_t *main)
{
    main->window->cursor = sfSprite_create();
    main->window->displayCursor = 0;
    main->window->v_sync = 1;
    main->window->fps = 144;
    main->window->size = (sfVector2i){1066, 600};
    main->window->mode = (sfVideoMode){main->window->size.x,
    main->window->size.y, 32};
    main->window->sound = 100;
    main->window->fullscreen = 0;
}

void init_window(main_t *main)
{
    sfView const *view;

    main->window = malloc(sizeof(window_t));
    if (!load_conf(main))
        init_spec_windows(main);
    main->window->screen = sfRenderWindow_create(main->window->mode,
    "My RPG", main->window->fullscreen ? sfFullscreen : sfClose, NULL);
    sfRenderWindow_setFramerateLimit(main->window->screen, main->window->fps);
    sfRenderWindow_setVerticalSyncEnabled(main->window->screen, 1);
    main->window->gameView =
    sfView_copy(sfRenderWindow_getView(main->window->screen));
    main->window->menuView = sfView_copy(main->window->gameView);
    sfRenderWindow_setView(main->window->screen, main->window->menuView);
    view = sfRenderWindow_getDefaultView(main->window->screen);
    main->window->gameView = sfView_copy(view);
    main->window->menuView = sfView_copy(view);
    main->window->isClickHold = 0;
}
