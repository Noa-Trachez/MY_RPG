/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Boss fight states
*/

#include "my_rpg.h"

void boss_fight_state_a(main_t *main)
{
    sfFloatRect rect = (sfFloatRect){5345, 3850, 128, 20};

    for (int i = 0; i < 4; i++)
        if (sfFloatRect_intersects(&main->game->player->hitbox[i], &rect, 0)) {
            toggle_doors(main, DOOR_ARENA);
            boss_fight_state(1, 1);
        }
}

void boss_fight_state_b(main_t *main)
{
    toggle_doors(main, DOOR_ARENA);
    add_quest_popup(&main->hud->questHud, "\tYOU DEFEATED THE BOSS !!!");
    get_goals(main, QU_ARENA);
    boss_fight_state(0, 1);
}
