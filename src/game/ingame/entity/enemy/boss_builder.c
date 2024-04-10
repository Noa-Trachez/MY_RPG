/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Boss builder
*/

#include "my_rpg.h"

static enemies_t *init_boss_values(__attribute((unused))main_t *main,
sfVector2f pos)
{
    enemies_t *enemies;

    enemies = malloc(sizeof(enemies_t));
    *enemies = DEFAULT_BOSS;
    enemies->sprite = sfRectangleShape_create();
    enemies->clock = sfClock_create();
    enemies->shot = sfClock_create();
    enemies->items = malloc(sizeof(items_t));
    memset(enemies->items, 0, sizeof(items_t));
    create_object(enemies->items, URANIUM);
    enemies->items->id = ID_URANIUM;
    enemies->pos = pos;
    sfRectangleShape_setPosition(enemies->sprite, pos);
    sfRectangleShape_setOrigin(enemies->sprite,
    (sfVector2f){ENEMIES_RECT[4].width / 2, ENEMIES_RECT[4].height / 2});
    sfRectangleShape_setSize(enemies->sprite,
    (sfVector2f){ENEMIES_RECT[4].width, ENEMIES_RECT[4].height});
    sfRectangleShape_setTexture(enemies->sprite, get_objects(), 0);
    sfRectangleShape_setTextureRect(enemies->sprite, ENEMIES_RECT[4]);
    return (enemies);
}

void build_boss(__attribute((unused))main_t *main, enemies_t **enemies,
sfVector2f pos)
{
    enemies_t *head = *enemies;

    if (head) {
        while (head->next != NULL)
            head = head->next;
        head->next = init_boss_values(main, pos);
    } else {
        head = init_boss_values(main, pos);
        *enemies = head;
    }
}
