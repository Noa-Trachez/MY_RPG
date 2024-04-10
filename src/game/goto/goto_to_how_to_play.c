/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** goto_to_how_to
*/

#include "my_rpg.h"

void destroy_htp_menu(main_t *main)
{
    sfSprite_destroy(main->menu->htpMenu->sprite);
    free(main->menu->htpMenu);
    main->menu->htpMenu = NULL;
}

void goto_how(main_t *main)
{
    main->scene = 1;
    main->menu->htpMenu = malloc(sizeof(htpMenu_t));
    main->menu->htpMenu->sprite = sfSprite_create();
    sfSprite_setTexture(main->menu->htpMenu->sprite, get_htp(), sfTrue);
    sfSprite_setTextureRect(main->menu->htpMenu->sprite, HOW_TO_RECT[0]);
}
