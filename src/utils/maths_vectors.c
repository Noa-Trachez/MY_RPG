/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Useful maths vector functions
*/

#include "my_rpg.h"

sfVector2f angle_to_vector(float angle, float velocity)
{
    sfVector2f vector;
    float rad = angle * (float)(MATH_PI / 180);

    vector = (sfVector2f){(float)cos((double)rad) * velocity,
    (float)sin((double)rad) * velocity};
    return (vector);
}
