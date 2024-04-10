/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Inventory ammo display
*/

#include "my_rpg.h"

static void display_ammo_text(window_t *window,
ammoContainer_t *ammo_container, int index)
{
    static sfText *text = NULL;
    char *str = NULL;
    sfVector2f pos[5] = {{1080, 780}, {1080, 815}, {1080, 850},
    {1080, 885}, {1080, 920}};
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};

    if (!text) {
        text = sfText_create();
        sfText_setFont(text, get_font());
    }
    str = int_to_str(((int *)ammo_container)[index]);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 30 * mode.x);
    sfText_setPosition(text, (sfVector2f){(pos[index].x + 60) * mode.x,
    (pos[index].y) * mode.y});
    sfRenderWindow_drawText(window->screen, text, 0);
    free(str);
}

void display_inventory_ammo(window_t *window, ammoContainer_t *ammo_container)
{
    static sfSprite *ammo_sprite = NULL;
    sfVector2f pos[5] = {{1080, 780}, {1080, 815}, {1080, 850},
    {1080, 885}, {1080, 920}};
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};

    if (!ammo_sprite) {
        ammo_sprite = sfSprite_create();
        sfSprite_setTexture(ammo_sprite, get_objects(), 0);
    }
    for (int i = 0; i < 5; i++) {
        sfSprite_setTextureRect(ammo_sprite, AMMO_RECT[i]);
        sfSprite_setPosition(ammo_sprite,
        (sfVector2f){pos[i].x * mode.x, pos[i].y * mode.y});
        sfSprite_setScale(ammo_sprite, (sfVector2f){1 * mode.x, 1 * mode.y});
        sfRenderWindow_drawSprite(window->screen, ammo_sprite, 0);
        display_ammo_text(window, ammo_container, i);
    }
}
