/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Player animations
*/

#include "my_rpg.h"

void set_player_size(player_t *player)
{
    sfIntRect rect = sfRectangleShape_getTextureRect(player->sprite);

    sfRectangleShape_setSize(player->sprite,
    (sfVector2f){rect.width, rect.height});
    sfRectangleShape_setOrigin(player->sprite, (sfVector2f){rect.width / 2,
    rect.height / 2});
    sfRectangleShape_setScale(player->sprite, (sfVector2f){0.6, 0.6});
}

void set_player_dir(player_t *player, int index)
{
    if (index == 0)
        player->dir = (sfVector2i){-1, 0};
    if (index == 1)
        player->dir = (sfVector2i){0, -1};
    if (index == 2)
        player->dir = (sfVector2i){1, 0};
    if (index == 3)
        player->dir = (sfVector2i){0, 1};
}

int get_animation(sfVector2i dir)
{
    int x_dir = dir.x;
    int y_dir = dir.y;

    if (y_dir == 0 && x_dir == 0)
        return (-1);
    if (x_dir == -1 && y_dir == 0)
        return (MOVE_LEFT);
    if (x_dir == 1 && y_dir == 0)
        return (MOVE_RIGHT);
    if (y_dir == -1 && x_dir == 0)
        return (MOVE_UP);
    if (y_dir == 1 && x_dir == 0)
        return (MOVE_DOWN);
    return (MOVE_DOWN);
}

void change_animation_dir(int tmp_dir, int *index, int *dir)
{
    if (tmp_dir != *dir) {
        *dir = tmp_dir;
        *index = 0;
    }
}

void player_movement_animation(player_t *player)
{
    static int index = 0;
    static int dir = 0;
    static sfIntRect last_rect = {0, 323, 76, 103};
    int tmp_dir = get_animation(player->dir);

    set_player_size(player);
    change_animation_dir(tmp_dir, &index, &dir);
    if (tmp_dir == -1) {
        sfRectangleShape_setTextureRect(player->sprite, last_rect);
        return;
    }
    if (!CHARACTER[0][dir][index + 1].width &&
    !CHARACTER[0][dir][index + 1].height)
        index = 0;
    sfRectangleShape_setTextureRect(player->sprite, CHARACTER[0][dir][index]);
    last_rect = CHARACTER[0][dir][index];
    index++;
    sfClock_restart(player->movement);
}
