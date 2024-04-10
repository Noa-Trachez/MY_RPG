/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Destroy buttons
*/

#include "my_rpg.h"

void destroy_button(buttons_t **buttons)
{
    buttons_t *head;

    while (*buttons) {
        head = *buttons;
        sfRectangleShape_destroy((*buttons)->sprite);
        *buttons = (*buttons)->next;
        free(head);
        head = NULL;
    }
    *buttons = NULL;
}
