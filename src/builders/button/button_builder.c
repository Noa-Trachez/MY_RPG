/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Build a new button
*/

#include "my_rpg.h"

static buttons_t *get_button_parameter(buttons_t *buttons, char
parameter, va_list list)
{
    static const char *button_parameters = "srzlpf";

    buttons_t *(*setter[])() = {&button_set_rectsh_scene,
    &button_set_rectsh_rect, &button_set_rectsh_size, &button_set_rectsh_scale,
    &button_set_rectsh_pos, &button_set_on_pressed};
    int parameter_i = -1;

    for (int i = 0; button_parameters[i]; i++)
        if (button_parameters[i] == parameter) {
            parameter_i = i;
            break;
        }
    setter[parameter_i](buttons, list);
    return (buttons);
}

static buttons_t *init_button_values(void)
{
    buttons_t *buttons;

    buttons = malloc(sizeof(buttons_t));
    *buttons = default_button;
    buttons->sprite = sfRectangleShape_create();
    sfRectangleShape_setTexture(buttons->sprite, get_interface(), 0);
    sfRectangleShape_setSize(buttons->sprite, buttons->size);
    return (buttons);
}

static buttons_t **new_button(buttons_t **buttons, char *parameters,
va_list list)
{
    buttons_t *head = *buttons;
    buttons_t *current = NULL;

    if (*buttons) {
        while ((*buttons)->next != NULL)
            *buttons = (*buttons)->next;
        (*buttons)->next = init_button_values();
        current = (*buttons)->next;
        *buttons = head;
    } else {
        *buttons = init_button_values();
        current = *buttons;
    }
    for (int i = 0; parameters[i]; i++)
        get_button_parameter(current, parameters[i], list);
    return (buttons);
}

void build_button(buttons_t **buttons, char *parameters, ...)
{
    va_list list;

    va_start(list, parameters);
    buttons = new_button(buttons, parameters, list);
    va_end(list);
}
