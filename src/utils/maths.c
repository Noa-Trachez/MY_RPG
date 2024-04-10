/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Useful maths functions
*/

#include "my_rpg.h"
#include <math.h>

sfVector2f move_towards(sfVector2f pos, sfVector2f target, float velocity)
{
    float vector_x = target.x - pos.x;
    float vector_y = target.y - pos.y;
    double angle = atan2f(vector_y, vector_x);
    float mx = velocity * (float)cos(angle);
    float my = velocity * (float)sin(angle);

    if (vector_x == 0 && vector_y == 0)
        return ((sfVector2f){0, 0});
    return ((sfVector2f){mx, my});
}

float face_towards(sfVector2f pos, sfVector2f target)
{
    float vector_x = target.x - pos.x;
    float vector_y = target.y - pos.y;
    float angle = atan2f(vector_y, vector_x);

    angle *= 180 / MATH_PI;
    angle += 90;
    return (angle);
}

int object_inrange(sfVector2f object1, sfVector2f object2, int range)
{
    float distance = (float)sqrt(pow((object2.x - object1.x), 2) +
    pow((object1.y - object2.y), 2));
    if (fabs(distance) <= (float)range)
        return (1);
    return (0);
}

float objects_delta(sfVector2f object1, sfVector2f object2)
{
    float distance = (float)sqrt(pow((object2.x - object1.x), 2) +
    pow((object1.y - object2.y), 2));

    return (distance);
}

int randnb(int min, int max)
{
    return (rand() % (max - min + 1) + min);
}
