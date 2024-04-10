/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Set new button values
*/

#include "my_rpg.h"

buttons_t *button_set_on_pressed(buttons_t *buttons, va_list list)
{
    int (*onPressed)() = va_arg(list, int (*)());
    buttons->onPressed = onPressed;
    return (buttons);
}

void toggle_button(buttons_t *buttons, buttons_t *to_toggle)
{
    buttons_t *head = buttons;

    while (head) {
        if (head == to_toggle){
            head->isEnable = !head->isEnable;
            return;
        }
        head = head->next;
    }
}
