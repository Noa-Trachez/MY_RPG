/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#ifndef MATHS_H
    #define MATHS_H

sfVector2f move_towards(sfVector2f pos, sfVector2f target, float velocity);
float face_towards(sfVector2f pos, sfVector2f target);
int object_inrange(sfVector2f object1, sfVector2f object2, int range);
float objects_delta(sfVector2f object1, sfVector2f object2);
int randnb(int min, int max);
sfVector2f angle_to_vector(float angle, float velocity);

#endif/*MATHS_H*/
