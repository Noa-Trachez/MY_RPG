/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Display quest hud
*/

#include "my_rpg.h"

void display_quest_hud(quest_hud_t *quest_hud, window_t *window, main_t *main)
{
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};

    if (!quest_hud)
        return;
    sfText_setCharacterSize(quest_hud->text, 25 * mode.x);
    sfRectangleShape_setPosition(quest_hud->rect,
    (sfVector2f){660 * mode.x, 20 * mode.y});
    sfText_setPosition(quest_hud->text,
    (sfVector2f){765 * mode.x, 50 * mode.y});
    sfRenderWindow_setView(window->screen, window->menuView);
    sfRenderWindow_drawRectangleShape(window->screen, quest_hud->rect, 0);
    sfRenderWindow_drawText(window->screen, quest_hud->text, 0);
    sfRenderWindow_setView(window->screen, window->gameView);
    if (sfTime_asSeconds(sfClock_getElapsedTime(quest_hud->clock)) < 0.05)
        return;
    update_quest_hud(quest_hud, mode, main->sound);
}

static quest_hud_t *new_quest_popup(char *str)
{
    quest_hud_t *quest_popup = malloc(sizeof(quest_hud_t));

    memset(quest_popup, 0, sizeof(quest_hud_t));
    quest_popup->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(quest_popup->rect, get_interface(), 0);
    sfRectangleShape_setTextureRect(quest_popup->rect,
    INTERFACE_SPRITE[IN_QUEST_ACCOMPLISH]);
    sfRectangleShape_setFillColor(quest_popup->rect,
    sfColor_fromRGBA(125, 125, 125, 0));
    quest_popup->text = sfText_create();
    sfText_setFont(quest_popup->text, get_font());
    sfText_setString(quest_popup->text, str);
    sfText_setColor(quest_popup->text,
    sfColor_fromRGBA(255, 255, 255, 0));
    quest_popup->clock = sfClock_create();
    return (quest_popup);
}

void add_quest_popup(quest_hud_t **quest_popup, char *str)
{
    quest_hud_t *head = *quest_popup;

    if (*quest_popup) {
        while ((*quest_popup)->next != NULL)
            *quest_popup = (*quest_popup)->next;
        (*quest_popup)->next = new_quest_popup(str);
        *quest_popup = head;
    } else
        *quest_popup = new_quest_popup(str);
}

void destroy_quest_popup(quest_hud_t **quest_popup)
{
    quest_hud_t *head = *quest_popup;
    quest_hud_t *save;

    if (head) {
        save = head;
        head = save->next;
        *quest_popup = head;
        sfRectangleShape_destroy(save->rect);
        sfText_destroy(save->text);
        free(save);
        save = NULL;
    }
}
