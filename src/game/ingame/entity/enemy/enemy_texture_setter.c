/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Set new enemy texture
*/

#include "my_rpg.h"

enemies_t *enemy_set_sprite_rect(enemies_t *enemies, va_list list)
{
    sfIntRect value = va_arg(list, sfIntRect);
    enemies->rect = value;
    sfRectangleShape_setTextureRect(enemies->sprite, enemies->rect);
    sfRectangleShape_setOrigin(enemies->sprite, (sfVector2f){(float)
    enemies->rect.width / 2, (float)enemies->rect.height / 2});
    return (enemies);
}

enemies_t *enemy_set_sprite_scale(enemies_t *enemies, va_list list)
{
    sfVector2f value = va_arg(list, sfVector2f);
    enemies->scale = value;
    sfRectangleShape_setScale(enemies->sprite, enemies->scale);
    return (enemies);
}

enemies_t *enemy_set_sprite_pos(enemies_t *enemies, va_list list)
{
    sfVector2f value = va_arg(list, sfVector2f);
    enemies->pos = value;
    sfRectangleShape_setPosition(enemies->sprite, enemies->pos);
    return (enemies);
}
