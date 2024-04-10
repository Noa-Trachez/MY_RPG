/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Main story manager
*/

#include "my_rpg.h"

void init_story(main_t *main)
{
    main->game->story = malloc(sizeof(story_t));
    story_t *story = main->game->story;

    story->isStoryDone = 2;
    story->wokeUp = 0;
    story->fadeColor = 255;
    story->playerRotation = 90;
    story->clock = sfClock_create();
    story->particleClock = sfClock_create();
}

void main_story(main_t *main)
{
    story_t *story = main->game->story;
    static int is_done = 0;

    if (!is_done)
        add_quest_popup(&main->hud->questHud, "PRESS I TO OPEN QUESTS MENU");
    if (!story->wokeUp && !story->isStoryDone)
        player_waking_up(main);
    is_done = 1;
}
