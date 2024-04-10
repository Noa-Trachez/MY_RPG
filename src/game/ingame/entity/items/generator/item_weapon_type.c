/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Item weapon type
*/

#include "my_rpg.h"

static void set_weapon_texture(items_t *item)
{
    int nb = randnb(0, 8);
    int type = item->weapon->type;

    while (!WEAPONS_RECT[type][nb].height)
        nb = randnb(0, 8);
    item->sprite = sfRectangleShape_create();
    sfRectangleShape_setTexture(item->sprite, get_objects(), 0);
    sfRectangleShape_setTextureRect(item->sprite, WEAPONS_RECT[type][nb]);
    sfRectangleShape_setSize(item->sprite,
    (sfVector2f){WEAPONS_RECT[type][nb].width, WEAPONS_RECT[type][nb].height});
    sfRectangleShape_setScale(item->sprite, (sfVector2f){0.5, 0.5});
}

static void set_ammo(weapon_t *weapon)
{
    weapon->maxAmmo = MAGAZINE(weapon->type, weapon->rarity);
    weapon->magazine = weapon->maxAmmo;
    weapon->reloadTime = RELOAD(weapon->type, weapon->rarity);
    int ammo_types[7] = {LIGHTAMMO, LIGHTAMMO, MEDIUMAMMO, SPECIALAMMO,
    HEAVYAMMO, HEAVYAMMO, EXPLOSIVEAMMO};

    weapon->ammoType = ammo_types[weapon->type];
}

static void set_stats(items_t *item, weapon_t *weapon)
{
    item->stats.damage = randnb(MIN_DAMAGE(weapon->type, weapon->rarity),
    MAX_DAMAGE(weapon->type, weapon->rarity));
    item->stats.attackSpeed = randnb(MIN_ATTACK(weapon->type, weapon->rarity),
    MAX_ATTACK(weapon->type, weapon->rarity));
    item->stats.endurance = randnb(MIN_SPEED(weapon->type, weapon->rarity),
    MAX_SPEED(weapon->type, weapon->rarity));
    item->weapon = weapon;
}

void create_weapon(items_t *item, int type, int rarity)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    memset(weapon, 0, sizeof(weapon_t));
    if (type == UNUSED)
        weapon->type = get_weapon_type();
    else
        weapon->type = type;
    if (rarity == UNUSED)
        weapon->rarity = get_rarity();
    else
        weapon->rarity = rarity;
    set_ammo(weapon);
    set_stats(item, weapon);
    set_weapon_texture(item);
}
