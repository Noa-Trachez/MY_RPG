/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Chest builder
*/

#include "my_rpg.h"

static chest_t *init_chest_values(all_chests_t all_chest)
{
    chest_t *chest = malloc(sizeof(chest_t));

    chest->isOpen = CHEST_CLOSE;
    chest->map = all_chest.map;
    chest->pos = all_chest.pos;
    chest->item = NULL;
    chest->sprite = sfRectangleShape_create();
    sfRectangleShape_setPosition(chest->sprite, chest->pos);
    sfRectangleShape_setFillColor(chest->sprite, sfYellow);
    sfRectangleShape_setSize(chest->sprite, (sfVector2f){45, 64});
    sfRectangleShape_setTexture(chest->sprite, get_objects(), 0);
    sfRectangleShape_setTextureRect(chest->sprite, CHEST_RECT[CHEST_CLOSE]);
    sfRectangleShape_setOrigin(chest->sprite, (sfVector2f){22.5, 32});
    chest->next = NULL;
    return (chest);
}

static chest_t **new_chest(chest_t **chests, all_chests_t all_chests)
{
    chest_t *head = *chests;

    if (*chests) {
        while ((*chests)->next != NULL)
            *chests = (*chests)->next;
        (*chests)->next = init_chest_values(all_chests);
        *chests = head;
    } else
        *chests = init_chest_values(all_chests);
    return (chests);
}

void build_chest(chest_t **chests, all_chests_t all_chests)
{
    chests = new_chest(chests, all_chests);
}
