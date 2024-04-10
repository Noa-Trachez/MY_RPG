/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Display sidebar
*/

#include "my_rpg.h"

void display_sidebar_items(player_t *player, window_t *window)
{
    equipedItems_t *equiped_items = player->equipedItems;
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};
    sfRectangleShape *weapon;

    for (int i = 0; i < 4; i++) {
        if (!equiped_items->slots[i])
            continue;
        weapon = sfRectangleShape_copy(equiped_items->slots[i]->sprite);
        sfRectangleShape_setPosition(weapon,
        (sfVector2f){(EQUIPMENT_SIDEBAR[i].x + 8) * mode.x,
        (EQUIPMENT_SIDEBAR[i].y + 8) * mode.y});
        sfRectangleShape_setSize(weapon,
        (sfVector2f){70 * mode.x, 70 * mode.y});
        sfRectangleShape_setFillColor(weapon,
        (i == equiped_items->currentSeclectedItem) ? sfWhite :
        sfColor_fromRGBA(100, 100, 100, 236));
        sfRenderWindow_drawRectangleShape(window->screen, weapon, 0);
        sfRectangleShape_destroy(weapon);
    }
}

void display_sidebar(player_t *player, window_t *window)
{
    static sfRectangleShape *sidebar = NULL;
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};

    if (sidebar == NULL) {
        sidebar = sfRectangleShape_create();
        sfRectangleShape_setTexture(sidebar, get_interface(), 0);
        sfRectangleShape_setTextureRect(sidebar, INTERFACE_SPRITE[IN_SIDEBAR]);
    }
    sfRenderWindow_setView(window->screen, window->menuView);
    sfRectangleShape_setPosition(sidebar,
    (sfVector2f){EQUIPMENT_SIDEBAR[4].x * mode.x,
    EQUIPMENT_SIDEBAR[4].y * mode.y});
    sfRectangleShape_setSize(sidebar, (sfVector2f){mode.x * 442.8,
    mode.y * 100.2});
    sfRenderWindow_drawRectangleShape(window->screen, sidebar, 0);
    display_sidebar_items(player, window);
    display_sidebar_ammo(player, window);
    display_sidebar_total_ammo(player, window);
    sfRenderWindow_setView(window->screen, window->gameView);
}
