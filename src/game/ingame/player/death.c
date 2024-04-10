/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Player death
*/

#include "my_rpg.h"

void player_respawn(player_t *player)
{
    player->pos = (sfVector2f){1680, -864};
    player->currentHealth = player->stats->health;
    sfRectangleShape_setPosition(player->sprite, player->pos);
    player->state->canShot = 1;
    player->state->canMove = 1;
}

void player_die(main_t *main, player_t *player)
{
    static int delay = 0;

    player->state->canMove = 0;
    player->state->canShot = 0;
    if (sfTime_asSeconds(sfClock_getElapsedTime(player->tick)) > 0.1) {
        new_circle_particles_cluster(main->particles, player->pos, 5);
        delay++;
        if (delay > 5) {
            player_respawn(player);
            delay = 0;
        }
        sfClock_restart(player->tick);
    }
}
