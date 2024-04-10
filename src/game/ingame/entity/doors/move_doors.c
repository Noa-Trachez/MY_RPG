/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** toggle_doors
*/

#include "my_rpg.h"

void close_doors(door_t *save)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(save->close)) < 0.01)
        return;
    if (sfRectangleShape_getSize(save->first).x >= 64)
        return;
    sfRectangleShape_setSize(save->first,
    (sfVector2f){sfRectangleShape_getSize(save->first).x + 1,
    sfRectangleShape_getSize(save->first).y});
    if (save->second) {
        sfRectangleShape_setSize(save->second,
        (sfVector2f){sfRectangleShape_getSize(save->second).x + 1,
        sfRectangleShape_getSize(save->second).y});
        sfRectangleShape_setPosition(save->second,
        (sfVector2f){sfRectangleShape_getPosition(save->second).x - 1,
        sfRectangleShape_getPosition(save->second).y});
    }
    sfClock_restart(save->close);
}

void open_doors(door_t *save)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(save->open)) < 0.01)
        return;
    if (sfRectangleShape_getSize(save->first).x <= 0)
        return;
    sfRectangleShape_setSize(save->first,
    (sfVector2f){sfRectangleShape_getSize(save->first).x - 1,
    sfRectangleShape_getSize(save->first).y});
    if (save->second) {
        sfRectangleShape_setSize(save->second,
        (sfVector2f){sfRectangleShape_getSize(save->second).x - 1,
        sfRectangleShape_getSize(save->second).y});
        sfRectangleShape_setPosition(save->second,
        (sfVector2f){sfRectangleShape_getPosition(save->second).x + 1,
        sfRectangleShape_getPosition(save->second).y});
    }
    sfClock_restart(save->open);
}

void move_doors(main_t *main)
{
    door_t *save = main->game->doors;

    while (save) {
        if (save->map != main->game->map->currentMap) {
            close_doors(save);
            save = save->next;
            continue;
        }
        if (save->activate &&
        object_inrange(main->game->player->pos, save->pos, save->range))
            open_doors(save);
        if (!object_inrange(main->game->player->pos, save->pos, save->range))
            close_doors(save);
        save = save->next;
    }
}
