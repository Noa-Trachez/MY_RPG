/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Story saving
*/

#include "my_rpg.h"

void save_story(game_t *game, int fd)
{
    story_t *story = game->story;

    write(fd, &story->isStoryDone, sizeof(int));
    write(fd, &story->wokeUp, sizeof(int));
    write(fd, &story->fadeColor, sizeof(int));
}
