/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Mouse events
*/

#include "my_rpg.h"

int is_mouse_on_rect(window_t *window, sfIntRect obj)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->screen);

    if (mouse_pos.x > obj.left && mouse_pos.y > obj.top && mouse_pos.x <
    obj.left + obj.width && mouse_pos.y < obj.top + obj.height)
        return 1;
    return 0;
}

int is_mouse_on_object(window_t *window, sfVector2f obj_pos, sfVector2f
obj_size, sfVector2f obj_scale)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->screen);
    float rx = (float)window->mode.width / (float)window->size.x;
    float ry = (float)window->mode.height / (float)window->size.y;
    float mousex = (float)mouse_pos.x;
    float mousey = (float)mouse_pos.y;

    if (((obj_pos.x - (obj_size.x * obj_scale.x) / 2) * rx <= mousex && mousex
    <= (obj_pos.x + (obj_size.x / 2 * obj_scale.x)) * rx) && ((obj_pos.y -
    (obj_size.y * obj_scale.y) / 2) * ry <= mousey && mousey <= (obj_pos.y +
    (obj_size.y / 2 * obj_scale.y)) * ry))
        return (1);
    return (0);
}

int is_mouse_on_world_object(window_t *window, sfIntRect object,
sfVector2f obj_pos)
{
    sfVector2f mpos = get_mouse_world_pos(window->screen, window->gameView);

    obj_pos = (sfVector2f){obj_pos.x - object.width / 2, obj_pos.y -
    object.height / 2};

    if ((obj_pos.x <= mpos.x && mpos.x <= obj_pos.x + (float)object.width) &&
    (obj_pos.y <= mpos.y && mpos.y <= obj_pos.y + (float)object.height))
        return (1);
    return (0);
}

sfVector2f get_mouse_world_pos(sfRenderWindow *window, sfView *view)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);
    sfVector2f world_pos;

    world_pos = sfRenderWindow_mapPixelToCoords(window, mpos, view);
    return (world_pos);
}
