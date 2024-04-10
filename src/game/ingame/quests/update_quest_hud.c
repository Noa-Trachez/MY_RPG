/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Update quest hud
*/

#include "my_rpg.h"

static void fade_in(quest_hud_t *quest_hud, int *state)
{
    sfRectangleShape_setFillColor(quest_hud->rect,
    sfColor_fromRGBA(125, 125, 125, quest_hud->opacity));
    sfText_setColor(quest_hud->text, sfColor_fromRGBA(255, 255, 255,
    quest_hud->opacity));
    quest_hud->opacity += 4;
    if (quest_hud->opacity >= 255) {
        quest_hud->opacity = 255;
        (*state)++;
    }
}

static void fade_out(quest_hud_t *quest_hud, int *state)
{
    sfRectangleShape_setFillColor(quest_hud->rect,
    sfColor_fromRGBA(125, 125, 125, quest_hud->opacity));
    sfText_setColor(quest_hud->text, sfColor_fromRGBA(255, 255, 255,
    quest_hud->opacity));
    quest_hud->opacity -= 4;
    if (quest_hud->opacity <= 0)
        (*state)++;
}

void update_quest_hud(quest_hud_t *quest_hud, sfVector2f mode, sound_t *sound)
{
    static int state = 0;

    sfRectangleShape_setSize(quest_hud->rect,
    (sfVector2f){600 * mode.x, 100 * mode.y});
    if (state == 0) {
        sfSound_play(sound->achievement);
        fade_in(quest_hud, &state);
    }
    if (state == 1)
        fade_out(quest_hud, &state);
    if (state == 2) {
        quest_hud->toBeDestroyed = 1;
        state = 0;
    }
    sfClock_restart(quest_hud->clock);
}
