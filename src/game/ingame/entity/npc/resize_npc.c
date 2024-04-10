/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Resize NPCs
*/

#include "my_rpg.h"

void resize_npc(window_t *window, npc_t *npc)
{
    static sfRectangleShape *textbox = NULL;
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};

    if (textbox == NULL) {
        textbox = sfRectangleShape_create();
        sfRectangleShape_setTexture(textbox, get_interface(), 0);
        sfRectangleShape_setTextureRect(textbox, INTERFACE_SPRITE[IN_TEXTBOX]);
    }
    sfRectangleShape_setSize(textbox,
    (sfVector2f){489 * mode.x, 171 * mode.y});
    sfRectangleShape_setPosition(textbox,
    (sfVector2f){710 * mode.x, 850 * mode.y});
    sfText_setCharacterSize(npc->text, 20 * mode.x);
    sfText_setPosition(npc->text, (sfVector2f){740 * mode.x, 880 * mode.y});
    sfRenderWindow_drawRectangleShape(window->screen, textbox, 0);
    sfRenderWindow_drawText(window->screen, npc->text, 0);
}
