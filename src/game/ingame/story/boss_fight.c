/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Boss fight manager
*/

#include "my_rpg.h"

int boss_fight_state(int value, int mod)
{
    static int state = 0;

    if (mod)
        state = value;
    return (state);
}

int is_boss_alive(enemies_t *enemies)
{
    enemies_t *head = enemies;

    while (head) {
        if (head->id == BOSS)
            return (1);
        head = head->next;
    }
    return (0);
}

void boss_fight(main_t *main)
{
    static int is_done = 0;
    int state = boss_fight_state(0, 0);
    int is_alive = is_boss_alive(main->enemies);

    if (!is_done && state == 0)
        boss_fight_state_a(main);
    if (state == 1) {
        build_boss(main, &main->enemies, (sfVector2f){3272, 5050});
        boss_fight_state(2, 1);
    }
    if (!is_done && state == 2 && !is_alive) {
        boss_fight_state_b(main);
        is_done = 1;
    }
}
