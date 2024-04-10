/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Load item list
*/

#include "my_rpg.h"

static void load_item_type(items_t *item, int fd)
{
    if (item->weapon) {
        item->weapon = malloc(sizeof(weapon_t));
        read(fd, item->weapon, sizeof(weapon_t));
    }
    if (item->ammo) {
        item->ammo = malloc(sizeof(ammo_t));
        read(fd, item->ammo, sizeof(ammo_t));
    }
    if (item->food) {
        item->food = malloc(sizeof(food_t));
        read(fd, item->food, sizeof(food_t));
    }
    if (item->object) {
        item->object = malloc(sizeof(object_t));
        read(fd, item->object, sizeof(object_t));
    }
}

static items_t *read_items(int fd)
{
    items_t *item = malloc(sizeof(items_t));

    memset(item, 0, sizeof(items_t));
    read(fd, item, sizeof(items_t));
    item->sprite = sfRectangleShape_create();
    sfRectangleShape_setTexture(item->sprite, get_objects(), 0);
    sfRectangleShape_setTextureRect(item->sprite, item->rect);
    load_item_type(item, fd);
    item->next = NULL;
    return (item);
}

static void build_saved_item(game_t *game, int fd)
{
    items_t *head = game->player->inventory;

    if (head) {
        while (head->next != NULL)
            head = head->next;
        head->next = read_items(fd);
    } else {
        head = read_items(fd);
        game->player->inventory = head;
    }
}

void load_items(game_t *game, int fd)
{
    int len = 0;

    read(fd, &len, sizeof(int));
    while (len--)
        build_saved_item(game, fd);
}
