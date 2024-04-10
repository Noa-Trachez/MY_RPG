/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Buttons state
*/

#include "my_rpg.h"

void button_display(window_t *window, buttons_t *buttons, int scene)
{
    buttons_t *head = buttons;

    if (scene == MAIN_MENU)
        sfRenderWindow_setView(window->screen, window->menuView);
    while (head) {
        if (!head->isEnable)
            sfRectangleShape_setFillColor(head->sprite,
            sfColor_fromRGBA(200, 200, 200, 80));
        if (head->scene == scene) {
            sfRenderWindow_drawRectangleShape(window->screen,
            head->sprite, 0);
        }
        head = head->next;
    }
    if (scene == MAIN_MENU)
        sfRenderWindow_setView(window->screen, window->gameView);
}

void button_is_hovered(buttons_t *buttons, window_t *window, int scene)
{
    while (buttons) {
        sfRectangleShape_setFillColor(buttons->sprite,
        (sfColor){255, 255, 255, 255});
        if (buttons->scene == scene && is_mouse_on_object(window, buttons->pos,
        buttons->size, buttons->scale) && buttons->isEnable) {
            sfRectangleShape_setFillColor(buttons->sprite,
            (sfColor){255, 255, 255, 190});
        }
        buttons = buttons->next;
    }
}

void button_is_pressed(buttons_t *buttons, window_t *window, int scene)
{
    while (buttons) {
        sfRectangleShape_setScale(buttons->sprite, (sfVector2f)
        {buttons->scale.x, buttons->scale.y});
        if (buttons->onPressed != NULL && buttons->scene == scene &&
        is_mouse_on_object(window, buttons->pos, buttons->size,
        buttons->scale) && buttons->isEnable) {
            buttons->isPressed = 1;
            sfRectangleShape_setScale(buttons->sprite, (sfVector2f)
            {buttons->scale.x * 0.9, buttons->scale.y * 0.9});
        }
        buttons = buttons->next;
    }
}

void button_is_released(main_t *main, buttons_t *buttons, window_t *window,
int scene)
{
    int index = 0;

    while (buttons) {
        if (buttons->onPressed != NULL && buttons->scene == scene &&
        is_mouse_on_object(window, buttons->pos, buttons->size,
        buttons->scale) && buttons->isPressed && buttons->isEnable) {
            set_global(&g_last_pressed_button, index);
            sfRectangleShape_setScale(buttons->sprite, (sfVector2f)
            {buttons->scale.x, buttons->scale.y});
            play_onclick_sound(main);
            buttons->isPressed = 0;
            buttons->onPressed(main);
            break;
        }
        sfRectangleShape_setScale(buttons->sprite,
        (sfVector2f) {buttons->scale.x, buttons->scale.y});
        buttons->isPressed = 0;
        buttons = buttons->next;
        index++;
    }
}

int g_last_pressed_button(int value, int mod)
{
    static int no = 0;

    if (mod)
        no = value;
    return (no);
}
