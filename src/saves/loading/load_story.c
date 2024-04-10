/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Load story from save
*/

#include "my_rpg.h"

void load_story(game_t *game, int fd)
{
    story_t *story = game->story;

    read(fd, &story->isStoryDone, sizeof(int));
    read(fd, &story->wokeUp, sizeof(int));
    read(fd, &story->fadeColor, sizeof(int));
}
