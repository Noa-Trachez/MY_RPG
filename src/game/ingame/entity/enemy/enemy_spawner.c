/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Enemy spawner
*/

#include "my_rpg.h"

void spawn_enemy(main_t *main, int number, __attribute__((unused))int unit,
int spawner)
{
    int x_pos = 0;
    int y_pos = 0;
    sfVector2f player_pos = main->game->player->pos;

    if (!check_quest(main, QU_FIRST_WEAPON) || main->game->map->currentMap
    != MAP || sfTime_asSeconds(sfClock_getElapsedTime(main->enemy_spawner)) <
    main->random_spawner + 3)
        return;
    sfClock_restart(main->enemy_spawner);
    main->random_spawner = rand() % 2;
    for (int i = 0; i < number; i++) {
        x_pos = randnb(SPAWN_POS[spawner][0].x, SPAWN_POS[spawner][1].x);
        y_pos = randnb(SPAWN_POS[spawner][0].y, SPAWN_POS[spawner][1].y);
        if (object_inrange((sfVector2f){x_pos, y_pos}, player_pos, 120) == 0) {
            build_enemy(main, &main->enemies, "ph", (sfVector2f){x_pos, y_pos},
            (int)(50));
        }
    }
}

void show_spawners(sfRenderWindow *window, sfColor color, int spawner)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setOutlineColor(shape, color);
    sfRectangleShape_setOutlineThickness(shape, 10);
    sfRectangleShape_setSize(shape,
    (sfVector2f){SPAWN_POS[spawner][1].x - SPAWN_POS[spawner][0].x,
    SPAWN_POS[spawner][1].y - SPAWN_POS[spawner][0].y});
    sfRectangleShape_setPosition(shape, (sfVector2f){SPAWN_POS[spawner][0].x,
    SPAWN_POS[spawner][0].y});
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}
