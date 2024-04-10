/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Binding menu key setter
*/

#include "my_rpg.h"

int get_key_code_index(main_t *main, int index)
{
    if (index == 0)
        return (main->key_code->up);
    if (index == 1)
        return (main->key_code->down);
    if (index == 2)
        return (main->key_code->right);
    if (index == 3)
        return (main->key_code->left);
    if (index == 4)
        return (main->key_code->inventory);
    if (index == 5)
        return (main->key_code->interact);
    return 0;
}

void set_key_to_change(main_t *main)
{
    main->key_code->key_to_change = g_last_pressed_button(0, 0);
}
