/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Binding events
*/

#include "my_rpg.h"

void binding_event(main_t *main)
{
    if (main->event.type == sfEvtKeyPressed &&
    main->event.key.code == sfKeyEscape && !main->key_code->key_to_change) {
        main->scene = SETTINGS_MENU;
        free_node_binding(&main->key_code->binding);
    }
    if (main->event.type == sfEvtKeyPressed &&
    main->key_code->key_to_change)
        error_change_key_bind(main);
}
