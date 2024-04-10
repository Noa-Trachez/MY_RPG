/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Set new enemy values
*/

#include "my_rpg.h"

enemies_t *enemy_set_health(enemies_t *enemies, va_list list)
{
    int value = va_arg(list, int);
    enemies->health = value;
    return (enemies);
}

enemies_t *enemy_set_damage(enemies_t *enemies, va_list list)
{
    int value = va_arg(list, int);
    enemies->damage = value;
    return (enemies);
}

enemies_t *enemy_set_speed(enemies_t *enemies, va_list list)
{
    float value = va_arg(list, double);
    enemies->speed = value;
    return (enemies);
}
