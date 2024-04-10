/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Infos saving
*/

#include "my_rpg.h"

static float get_quest_total(quest_t *quests)
{
    float count = 0;
    quest_t *head = quests;

    while (head) {
        count++;
        head = head->next;
    }
    return (count);
}

static float get_quest_completed(quest_t *quests)
{
    float count = 0;
    quest_t *head = quests;

    while (head) {
        if (head->accomplish)
            count++;
        head = head->next;
    }
    return (count);
}

void save_infos(game_t *game, int fd)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(game->timePlayed)) +
    game->timePlayedAsSecond;
    float quest_percentage = get_quest_completed(game->quest) /
    get_quest_total(game->quest) * 100;

    write(fd, &time, sizeof(float));
    write(fd, &quest_percentage, sizeof(float));
    sfClock_restart(game->timePlayed);
}
