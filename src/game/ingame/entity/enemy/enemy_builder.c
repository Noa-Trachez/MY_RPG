/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Enemy builder
*/

#include "my_rpg.h"

static enemies_t *get_enemy_parameter(enemies_t *buttons, char
parameter, va_list list)
{
    static const char *button_parameters = "hdsrlp";

    enemies_t *(*setter[])() = {&enemy_set_health,
    &enemy_set_damage, &enemy_set_speed, &enemy_set_sprite_rect,
    &enemy_set_sprite_scale, &enemy_set_sprite_pos};
    int parameter_i = -1;

    for (int i = 0; button_parameters[i]; i++)
        if (button_parameters[i] == parameter) {
            parameter_i = i;
            break;
        }
    setter[parameter_i](buttons, list);
    return (buttons);
}

static enemies_t *init_enemy_values(main_t *main)
{
    enemies_t *enemies;
    int random = randnb(30, 50);

    enemies = malloc(sizeof(enemies_t));
    *enemies = DEFAULT_ENEMY;
    enemies->sprite = sfRectangleShape_create();
    enemies->clock = sfClock_create();
    enemies->shot = sfClock_create();
    enemies->items = build_item_enemies(main);
    sfRectangleShape_setOrigin(enemies->sprite,
    (sfVector2f){random / 2, random / 2});
    sfRectangleShape_setSize(enemies->sprite, (sfVector2f){random, random});
    sfRectangleShape_setTexture(enemies->sprite, get_objects(), 0);
    sfRectangleShape_setTextureRect(enemies->sprite,
    ENEMIES_RECT[randnb(0, 4)]);
    return (enemies);
}

static enemies_t **new_enemy(main_t *main, enemies_t **enemies,
char *parameters, va_list list)
{
    enemies_t *head = *enemies;
    enemies_t *current = NULL;

    if (*enemies) {
        while ((*enemies)->next != NULL)
            *enemies = (*enemies)->next;
        (*enemies)->next = init_enemy_values(main);
        current = (*enemies)->next;
        *enemies = head;
    } else {
        *enemies = init_enemy_values(main);
        current = *enemies;
    }
    for (int i = 0; parameters[i]; i++)
        get_enemy_parameter(current, parameters[i], list);
    return (enemies);
}

void build_enemy(main_t *main, enemies_t **enemies, char *parameters, ...)
{
    va_list list;

    va_start(list, parameters);
    enemies = new_enemy(main, enemies, parameters, list);
    va_end(list);
}
