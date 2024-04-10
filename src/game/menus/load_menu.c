/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Load menu
*/

#include "my_rpg.h"

void destroy_load_menu(menu_t *menu, saves_t *saves)
{
    saves_t *tmp;

    sfRectangleShape_destroy(menu->loadMenu->rect);
    free(menu->loadMenu);
    while (saves) {
        tmp = saves;
        if (saves->background)
            sfSprite_destroy(saves->background);
        if (saves->sprite)
            sfRectangleShape_destroy(saves->sprite);
        if (saves->text)
            sfText_destroy(saves->text);
        if (saves->time)
            sfText_destroy(saves->time);
        saves = saves->next;
        free(tmp);
    }
    menu->loadMenu = NULL;
}

void load_menu(main_t *main)
{
    saves_t *head = main->saves;

    while (head) {
        sfRenderWindow_drawSprite(main->window->screen, head->background, 0);
        if (head->sprite)
            sfRenderWindow_drawRectangleShape(main->window->screen,
            head->sprite, 0);
        if (head->text)
            sfRenderWindow_drawText(main->window->screen, head->text, 0);
        if (head->time)
            sfRenderWindow_drawText(main->window->screen, head->time, 0);
        head = head->next;
    }
    sfRenderWindow_drawRectangleShape(main->window->screen,
    main->menu->loadMenu->rect, 0);
}
