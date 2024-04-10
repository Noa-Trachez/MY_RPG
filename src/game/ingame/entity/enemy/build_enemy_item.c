/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Build enemy item
*/

#include "my_rpg.h"

static void create_object_enemies(items_t *item, int my_object)
{
    object_t *object = malloc(sizeof(object_t));
    object->count = 1;

    free(item->weapon);
    free(item->ammo);
    item->weapon = NULL;
    item->ammo = NULL;
    sfRectangleShape_setTexture(item->sprite, get_objects(), 0);
    sfRectangleShape_setTextureRect(item->sprite, OBJECTS_RECTS[my_object]);
    sfRectangleShape_setSize(item->sprite, (sfVector2f){10, 10});
    sfRectangleShape_setScale(item->sprite, (sfVector2f){4, 4});
    item->object = object;
}

int check_quest(main_t *main, int type)
{
    quest_t *quest = main->game->quest;

    for (; quest; quest = quest->next)
        if (quest->type == type && quest->accomplish == 1)
            return 1;
    return 0;
}

int check_special_piece(main_t *main, items_t *item)
{
    if (randnb(0, 50) == 50 && !check_quest(main, QU_SPECIAL_PIECE)) {
        item->id = SPECIAL_PIECE;
        return 1;
    }
    return 0;
}

int check_metal(main_t *main, items_t *item)
{
    if (check_quest(main, QU_SPECIAL_PIECE)) {
        item->id = METAL;
        return 1;
    }
    return 0;
}

items_t *build_item_enemies(main_t *main)
{
    int random = randnb(0, 0);
    items_t *item;
    int (*fptr[])() = {&returned, &check_special_piece, &check_metal};

    item = build_item(-1);
    if (random && fptr[random](main, item))
        create_object_enemies(item, random);
    item->next = NULL;
    return (item);
}
