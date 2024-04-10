/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Enemy state
*/

#include "my_rpg.h"

void enemy_display(window_t *window, enemies_t *enemies, int current_map)
{
    enemies_t *head = enemies;

    while (head) {
        if (head->map != current_map) {
            head->toBeDestroyed = 1;
            head = head->next;
            continue;
        }
        sfRenderWindow_drawRectangleShape(window->screen, head->sprite, 0);
        if (head->health <= 0)
            head->toBeDestroyed = 1;
        head = head->next;
    }
}

void enemy_moving(map_t *map, enemies_t *enemies, player_t *player)
{
    enemies_t *head = enemies;

    while (head) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(head->clock)) < 0.02 ||
        object_inrange(head->pos, player->pos, 400)) {
            head = head->next;
            continue;
        }
        head->pos = sfRectangleShape_getPosition(head->sprite);
        head->destination = get_path(map, head->pos);
        sfRectangleShape_move(head->sprite, move_towards(head->pos,
        head->destination, head->speed));
        sfRectangleShape_setRotation(head->sprite, (float)face_towards
        (sfRectangleShape_getPosition(head->sprite), head->destination));
        sfClock_restart(head->clock);
        head = head->next;
    }
}

void free_enemy(enemies_t *enemy)
{
    sfRectangleShape_destroy(enemy->sprite);
    sfClock_destroy(enemy->clock);
    free(enemy);
}

void destroy_enemies(enemies_t **enemies)
{
    enemies_t *head = *enemies;
    enemies_t *save;

    if (head && head->toBeDestroyed) {
        save = head;
        head = save->next;
        *enemies = head;
        free_enemy(save);
        save = NULL;
    }
    while (head) {
        if (head->next && head->next->toBeDestroyed) {
            save = head->next;
            head->next = save->next;
            free_enemy(save);
            save = NULL;
        }
        head = head->next;
    }
}

void enemy_drop(main_t *main, enemies_t *enemy)
{
    enemies_t *head = enemy;

    while (head) {
        if (!head->toBeDestroyed) {
            head = head->next;
            continue;
        }
        if (check_quest(main, QU_FARMER))
            get_goals(main, QU_DO_GOLD);
        get_goals(main, QU_KILLS);
        drop_item(&head->items, &main->game->onGroundItems, head->pos,
        main->game->map->currentMap);
        head = head->next;
    }
}
