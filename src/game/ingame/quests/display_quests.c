/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Display quests
*/

#include "my_rpg.h"

void draw_desc(main_t *main, int i)
{
    char *nb = NULL;
    int count = 0;
    quest_t *quest = main->game->quest;

    for (; quest; quest = quest->next) {
        if (quest->mandatory == 0 && quest->accomplish == 0)
            count++;
        if (count == i + 1)
            break;
    }
    if (!quest)
        return;
    nb = my_strdup(quest->earned);
    nb = my_strappend(nb, int_to_str(quest->nb), 1);
    nb = my_strappend(nb, "/", 1);
    nb = my_strappend(nb, int_to_str(quest->total), 1);
    sfText_setString(quest->sentence, nb);
    resize_quest_desc(main, quest);
}

void quests(main_t *main)
{
    int count = 0;
    quest_t *quest = main->game->quest;

    resize_quests(main);
    is_mouse_on_quest(main);
    for (; quest; quest = quest->next)
        if (quest->mandatory == 0 && quest->accomplish == 0 && count < 4) {
            sfRenderWindow_drawText(main->window->screen, quest->text, 0);
            count++;
        }
}

void quest_manager(main_t *main)
{
    static sfTexture *texture = NULL;
    static sfText *desc = NULL;
    static sfSprite *sprite = NULL;

    display_quest_hud(main->hud->questHud, main->window, main);
    if (main->hud->questHud && main->hud->questHud->toBeDestroyed)
        destroy_quest_popup(&main->hud->questHud);
    if (main->game->player->state->inQuests == 0)
        return;
    if (texture == NULL) {
        texture = get_interface();
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setTextureRect(sprite, INTERFACE_SPRITE[IN_QUEST]);
        desc = create_text("Description", 40, (sfVector2f){1230, 160});
    }
    sfRenderWindow_setView(main->window->screen, main->window->menuView);
    resize_quests_manager(main, sprite, desc);
    quests(main);
    sfRenderWindow_setView(main->window->screen, main->window->gameView);
}
