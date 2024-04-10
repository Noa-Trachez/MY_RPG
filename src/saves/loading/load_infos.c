/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Infos saving
*/

#include "my_rpg.h"

void get_save_infos(char *save, float *time_played, float *quests_percentage)
{
    int fd = open(save, O_CREAT | O_RDONLY, 0664);

    if (fd < 0) {
        write(2, "Error: Can't open ", 18);
        write(2, save, 10);
        return;
    }
    read(fd, time_played, sizeof(float));
    read(fd, quests_percentage, sizeof(float));
    close(fd);
}

void load_infos(game_t *game, int fd)
{
    float tmp = 0;

    read(fd, &game->timePlayedAsSecond, sizeof(float));
    read(fd, &tmp, sizeof(float));
}
