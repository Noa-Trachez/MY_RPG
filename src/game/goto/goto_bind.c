/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Goto bind menu
*/

#include "my_rpg.h"

void goto_bind(main_t *main)
{
    main->scene = BINDING;
    main->key_code->binding = NULL;
    main->key_code->key_to_change = 0;
    char *str[] = {"Avancer :", "Reculer :", "Droite :", "Gauche :",
    "Inventaire :", "Interagir :"};
    float height[] = {13.5, 5.8, 3.6, 2.6, 2.05, 1.68};

    for (int i = 0; i < 6; i++)
        append_nodes_binding(&main->key_code->binding, str[i],
        (sfVector2f){main->window->mode.width / 11,
        main->window->mode.height / height[i]}, main->window->mode);
    load_binding_text(main);
}
