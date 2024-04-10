/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** NPCs builder
*/

#include "my_rpg.h"

void set_npc_specs(npc_t *new_npc, spec_t spec, const char *talk[7][9])
{
    int i = 0;
    for (; talk[i][0]; i++);
    new_npc->total = i;
    new_npc->index = -1;
    new_npc->selector = 0;
    new_npc->isSelected = 0;
    new_npc->map = spec.map;
    new_npc->sprite = sfRectangleShape_create();
    sfRectangleShape_setOrigin(new_npc->sprite, (sfVector2f){24, 36});
    sfRectangleShape_setPosition(new_npc->sprite, spec.pos);
    sfRectangleShape_setSize(new_npc->sprite, (sfVector2f){48, 72});
    sfRectangleShape_setTexture(new_npc->sprite, get_npc(), 0);
    sfRectangleShape_setTextureRect(new_npc->sprite, spec.rect);
    new_npc->text = create_text(talk[0][0], 20, (sfVector2f){710, 900});
}

npc_t *new_npc(npc_t *npc, spec_t spec, const char *talk[7][9])
{
    npc_t *new_npc = malloc(sizeof(npc_t));
    set_npc_specs(new_npc, spec, talk);
    new_npc->next = NULL;
    if (npc == NULL)
        new_npc->prev = NULL;
    else {
        new_npc->prev = npc;
        new_npc->prev->next = new_npc;
    }
    return new_npc;
}
