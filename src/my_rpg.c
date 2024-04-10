/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Main loop of the game
*/

#include "my_rpg.h"

int my_rpg(void)
{
    main_t *main = malloc(sizeof(main_t));

    game_init(main);
    while (sfRenderWindow_isOpen(main->window->screen)) {
        while (sfRenderWindow_pollEvent(main->window->screen, &main->event))
            event_manager(main);
        sfRenderWindow_clear(main->window->screen, sfBlack);
        game_loop(main);
        button_display(main->window, main->buttons, main->scene);
        sfRenderWindow_display(main->window->screen);
    }
    destroy_sound(main);
    save_conf(main);
    return (0);
}
