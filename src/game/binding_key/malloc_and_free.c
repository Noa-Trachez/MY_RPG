/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Binding Menu memory management
*/

#include "my_rpg.h"

void build_binding_button(main_t *main)
{
    float height[] = {10, 5, 1.95, 2.45, 3.3, 1.6};

    for (int i = 0; i < 6; i++)
        build_button(&main->buttons, "srzpf", BINDING, (sfIntRect){0, 0, 0, 0},
        (sfVector2f){120, 50}, (sfVector2f){main->window->mode.width / 1.2,
        main->window->mode.height / height[i]}, &set_key_to_change);
}

info_binding_t *init_nodes(char *str, sfVector2f pos, sfVideoMode mode)
{
    info_binding_t *node = malloc(sizeof(info_binding_t));
    float diff = mode.width / 1066.0;

    node->info = create_text(str, 25 * diff, pos);
    node->next = NULL;
    node->key_bind = NULL;
    return (node);
}

void append_nodes_binding(info_binding_t **binding, char *str, sfVector2f pos,
sfVideoMode mode)
{
    info_binding_t *info_binding = (*binding);

    if (*binding) {
        while ((*binding)->next != NULL)
            (*binding) = (*binding)->next;
        (*binding)->next = init_nodes(str, pos, mode);
        (*binding) = info_binding;
    } else
        (*binding) = init_nodes(str, pos, mode);
}

void free_node_binding(info_binding_t **binding)
{
    info_binding_t *tmp;

    while (*binding) {
        sfText_destroy((*binding)->key_bind);
        if ((*binding)->info)
            sfText_destroy((*binding)->info);
        tmp = *binding;
        *binding = (*binding)->next;
        free(tmp);
    }
}
