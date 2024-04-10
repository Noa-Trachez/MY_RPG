/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Set new button texture
*/

#include "my_rpg.h"

buttons_t *button_set_rectsh_scene(buttons_t *buttons, va_list list)
{
    int value = va_arg(list, int);
    buttons->scene = value;
    return (buttons);
}

buttons_t *button_set_rectsh_rect(buttons_t *buttons, va_list list)
{
    sfIntRect value = va_arg(list, sfIntRect);
    buttons->rect = value;
    buttons->size = (sfVector2f){value.width, value.height};
    sfRectangleShape_setTextureRect(buttons->sprite, buttons->rect);
    sfRectangleShape_setSize(buttons->sprite, buttons->size);
    sfRectangleShape_setOrigin(buttons->sprite, (sfVector2f){buttons->size.x
    / 2, buttons->size.y / 2});
    return (buttons);
}

buttons_t *button_set_rectsh_size(buttons_t *buttons, va_list list)
{
    sfVector2f value = va_arg(list, sfVector2f);
    buttons->size = value;
    sfRectangleShape_setSize(buttons->sprite, buttons->size);
    sfRectangleShape_setOrigin(buttons->sprite, (sfVector2f){buttons->size.x
    / 2, buttons->size.y / 2});
    return (buttons);
}

buttons_t *button_set_rectsh_scale(buttons_t *buttons, va_list list)
{
    sfVector2f value = va_arg(list, sfVector2f);
    buttons->scale = value;
    sfRectangleShape_setScale(buttons->sprite, buttons->scale);
    return (buttons);
}

buttons_t *button_set_rectsh_pos(buttons_t *buttons, va_list list)
{
    sfVector2f value = va_arg(list, sfVector2f);
    buttons->pos = value;
    sfRectangleShape_setPosition(buttons->sprite, buttons->pos);
    return (buttons);
}
