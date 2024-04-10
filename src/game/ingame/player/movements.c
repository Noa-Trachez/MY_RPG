/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Player movements
*/

#include "my_rpg.h"

void player_hitbox(player_t *player)
{
    sfFloatRect *hitbox = player->hitbox;

    for (int i = 0; i < 4; i++)
        hitbox[i] = sfRectangleShape_getGlobalBounds(player->sprite);
    for (int i = 0; i < 4; i++) {
        hitbox[i] = (sfFloatRect){hitbox->left + hitboxes[i].left,
        hitbox->top + hitboxes[i].top, hitbox->width + hitboxes[i].width,
        hitbox->height + hitboxes[i].height};
    }
}

void player_camera(player_t *player, window_t *window)
{
    sfVector2f pos = player->pos;

    sfView_setCenter(window->gameView, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_setView(window->screen, window->gameView);
}

int player_collision(sfIntRect box, map_t *map)
{
    obstacle_t *head = map->obstacles;
    sfFloatRect hitbox_f;

    hitbox_f = (sfFloatRect){(float)box.left, (float)box.top,
    (float)box.width, (float)box.height};
    while (head) {
        if (sfFloatRect_intersects(&hitbox_f, &head->obstacle, 0))
            return (1);
        head = head->next;
    }
    return (0);
}

void move_player(main_t *main, player_t *player, int i, int key[4])
{
    map_t *map = main->game->map;
    int speed = player->stats->speed;
    sfVector2i offset[4] = {{-speed, 0}, {0, -speed}, {speed, 0}, {0, speed}};
    sfIntRect hitb = {player->hitbox[i].left + offset[i].x,
    player->hitbox[i].top + offset[i].y, player->hitbox[i].width,
    player->hitbox[i].height};

    if (sfKeyboard_isKeyPressed(key[i]) && !player_collision(hitb, map)) {
        set_player_dir(player, i);
        player->pos.x += (float)offset[i].x;
        player->pos.y += (float)offset[i].y;
        sfRectangleShape_setPosition(player->sprite, player->pos);
        get_goals(main, QU_MOVE);
        check_tp(main->game, player, hitb, main->game->map);
    }
}

void player_moves(main_t *main, player_t *player, __attribute((unused))
map_t *map)
{
    int key[4] = {main->key_code->left, main->key_code->up,
    main->key_code->right, main->key_code->down};

    player->dir = (sfVector2i){0, 0};
    for (int i = 0; i < 4; i++)
        move_player(main, player, i, key);
    sfClock_restart(player->tick);
}
