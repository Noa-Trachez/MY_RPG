/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Keys binding
*/

#include "my_rpg.h"

void special_keys(main_t *main, int key_code, float diff,
sfVector2f pos)
{
    char *str = NULL;

    if (key_code == sfKeyEnter)
        str = "ENTER";
    if (key_code == sfKeyLShift)
        str = "LSHIFT";
    if (key_code == sfKeyLControl)
        str = "LCONTROL";
    if (key_code == sfKeyTab)
        str = "TAB";
    if (key_code == sfKeySpace)
        str = "SPACE";
    main->key_code->binding->key_bind = create_text(str,
    25 * diff, pos);
}

void create_bind_text(main_t *main, int i, int width, int height)
{
    int tmp = get_key_code_index(main, i);
    char *alph[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
    "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    char *keys[] = {"Key_Left", "Key_Right", "Key_Up", "Key_Down"};
    float diff = main->window->mode.width / 1066.0;

    if (main->key_code->binding->key_bind)
        sfText_destroy(main->key_code->binding->key_bind);
    main->key_code->binding->key_bind = NULL;
    if (tmp >= sfKeyLeft) {
        main->key_code->binding->key_bind = create_text(
        keys[tmp - sfKeyLeft], 25 * diff, (sfVector2f){width, height});
    } else if (tmp >= sfKeyA && tmp <= sfKeyZ)
        main->key_code->binding->key_bind = create_text(alph[tmp],
        25 * diff, (sfVector2f){width, height});
    else
        special_keys(main, tmp, diff, (sfVector2f){width, height});
}

void load_binding_text(main_t *main)
{
    double height[] = {13.5, 5.8, 3.6, 2.6, 2.05, 1.68};
    info_binding_t *save = main->key_code->binding;

    for (int i = 0; i < 6; i++) {
        create_bind_text(main, i, main->window->mode.width / 2.5,
        main->window->mode.height / height[i]);
        main->key_code->binding = main->key_code->binding->next;
    }
    main->key_code->binding = save;
}

void change_key_bind(main_t *main)
{
    if (main->key_code->key_to_change == 15)
        main->key_code->up = main->event.key.code;
    if (main->key_code->key_to_change == 16)
        main->key_code->down = main->event.key.code;
    if (main->key_code->key_to_change == 17)
        main->key_code->inventory = main->event.key.code;
    if (main->key_code->key_to_change == 18)
        main->key_code->left = main->event.key.code;
    if (main->key_code->key_to_change == 19)
        main->key_code->right = main->event.key.code;
    if (main->key_code->key_to_change == 20)
        main->key_code->interact = main->event.key.code;
    main->key_code->key_to_change = 0;
    load_binding_text(main);
}

void error_change_key_bind(main_t *main)
{
    if (main->event.key.code == sfKeyEscape) {
        main->key_code->key_to_change = 0;
        return;
    }
    if (main->key_code->key_to_change < 15 ||
    main->key_code->key_to_change > 20)
        return;
    if ((main->event.key.code >= sfKeyA && main->event.key.code <= sfKeyZ) ||
    (main->event.key.code >= sfKeyLeft && main->event.key.code <= sfKeyDown) ||
    main->event.key.code == sfKeyEnter || main->event.key.code == sfKeyLShift
    || main->event.key.code == sfKeyLControl ||
    main->event.key.code == sfKeyTab || main->event.key.code == sfKeySpace)
        change_key_bind(main);
}
