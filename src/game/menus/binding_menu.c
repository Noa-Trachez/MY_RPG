/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Binding menu
*/

#include "my_rpg.h"

void binding_menu(main_t *main)
{
    info_binding_t *binding = main->key_code->binding;

    sfRenderWindow_drawSprite(main->window->screen, main->menu->background, 0);
    while (main->key_code->binding) {
        sfRenderWindow_drawText(main->window->screen,
        main->key_code->binding->info, 0);
        if (main->key_code->binding->key_bind)
            sfRenderWindow_drawText(main->window->screen,
            main->key_code->binding->key_bind, 0);
        main->key_code->binding = main->key_code->binding->next;
    }
    main->key_code->binding = binding;
}
