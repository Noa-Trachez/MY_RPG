/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Resize quests
*/

#include "my_rpg.h"

sfIntRect resize_mouse_rect(window_t *window, sfIntRect rect)
{
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};
    rect.left *= mode.x;
    rect.top *= mode.x;
    rect.width *= mode.x;
    rect.height *= mode.x;

    return rect;
}

void resize_quest_desc(main_t *main, quest_t *quest)
{
    sfVector2f mode = {(float)main->window->mode.width / 1920,
    (float)main->window->mode.height / 1080};

    sfText_setPosition(quest->desc,
    (sfVector2f){1120 * mode.x, 250 * mode.y});
    sfText_setPosition(quest->sentence,
    (sfVector2f){1120 * mode.x, 720 * mode.y});
    sfRectangleShape_setPosition(quest->sprite,
    (sfVector2f){1500 * mode.x, 700 * mode.x});
    sfText_setCharacterSize(quest->desc, 30 * mode.x);
    sfText_setCharacterSize(quest->sentence, 30 * mode.x);
    sfRectangleShape_setSize(quest->sprite,
    (sfVector2f){quest->scale.x * mode.x, quest->scale.y * mode.x});
    sfRenderWindow_drawText(main->window->screen, quest->desc, 0);
    sfRenderWindow_drawText(main->window->screen, quest->sentence, 0);
    sfRenderWindow_drawRectangleShape(main->window->screen, quest->sprite, 0);
}

void resize_quests(main_t *main)
{
    int count = 0;
    quest_t *quest = main->game->quest;
    sfVector2f pos;
    sfVector2f mode = {(float)main->window->mode.width / 1920,
    (float)main->window->mode.height / 1080};

    for (; quest; quest = quest->next)
        if (quest->mandatory == 0 && quest->accomplish == 0 && count < 4) {
            pos = (sfVector2f){QUESTPOS[count].x * mode.x,
            QUESTPOS[count].y * mode.y};
            sfText_setCharacterSize(quest->text, 30 * mode.x);
            sfText_setPosition(quest->text, pos);
            count++;
        }
}

void resize_quests_manager(main_t *main, sfSprite *sprite, sfText *desc)
{
    sfVector2f mode = {(float)main->window->mode.width / 1920,
    (float)main->window->mode.height / 1080};

    sfSprite_setScale(sprite, (sfVector2f){mode.x, mode.y});
    sfSprite_setPosition(sprite, (sfVector2f){60 * mode.x, 50 * mode.y});
    sfText_setCharacterSize(desc, 40 * mode.x);
    sfText_setPosition(desc,
    (sfVector2f){1230 * mode.x, 160 * mode.y});
    sfRenderWindow_drawSprite(main->window->screen, sprite, 0);
    sfRenderWindow_drawText(main->window->screen, desc, 0);
}
