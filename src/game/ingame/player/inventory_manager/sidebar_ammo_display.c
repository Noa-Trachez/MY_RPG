/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Sidebar ammo display
*/

#include "my_rpg.h"

static void display_ammo_text(player_t *player, window_t *window)
{
    static sfText *text = NULL;
    equipedItems_t *equiped = player->equipedItems;
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};
    char *str = NULL;

    if (!text) {
        text = sfText_create();
        sfText_setFont(text, get_font());
    }
    str = int_to_str(AMMOCONTAINER(equiped->slots
    [equiped->currentSeclectedItem]->weapon->ammoType));
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 25 * mode.x);
    sfText_setPosition(text, (sfVector2f){1600 * mode.x, 945 * mode.y});
    sfRenderWindow_drawText(window->screen, text, 0);
    free(str);
}

void display_sidebar_total_ammo(player_t *player, window_t *window)
{
    static sfSprite *ammo_sprite = NULL;
    equipedItems_t *equiped = player->equipedItems;
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};

    if (!ammo_sprite) {
        ammo_sprite = sfSprite_create();
        sfSprite_setTexture(ammo_sprite, get_objects(), 0);
    }
    if (!equiped->slots[equiped->currentSeclectedItem] || !equiped->slots
    [equiped->currentSeclectedItem]->weapon)
        return;
    sfSprite_setTextureRect(ammo_sprite, AMMO_RECT[equiped->slots
    [equiped->currentSeclectedItem]->weapon->ammoType]);
    sfSprite_setPosition(ammo_sprite,
    (sfVector2f){1550 * mode.x, 945 * mode.y});
    sfSprite_setScale(ammo_sprite, (sfVector2f){0.9 * mode.x, 0.9 * mode.y});
    sfRenderWindow_drawSprite(window->screen, ammo_sprite, 0);
    display_ammo_text(player, window);
}

void display_sidebar_ammo(player_t *player, window_t *window)
{
    static sfText *text = NULL;
    equipedItems_t *equiped = player->equipedItems;
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};
    char *ammo_nb = NULL;

    if (text == NULL)
        text = create_text("", 17, (sfVector2f){1499, 1020});
    if (!equiped->slots[equiped->currentSeclectedItem] || !equiped->slots
    [equiped->currentSeclectedItem]->weapon)
        return;
    ammo_nb = my_strdup(int_to_str(equiped->slots
    [equiped->currentSeclectedItem]->weapon->magazine));
    ammo_nb = my_strappend(ammo_nb, "\n\n", 1);
    ammo_nb = my_strappend(ammo_nb, int_to_str(equiped->slots
    [equiped->currentSeclectedItem]->weapon->maxAmmo), 1);
    sfText_setString(text, ammo_nb);
    sfText_setCharacterSize(text, 17 * mode.x);
    sfText_setPosition(text, (sfVector2f){1499 * mode.x, 1020 * mode.y});
    sfRenderWindow_drawText(window->screen, text, 0);
}
