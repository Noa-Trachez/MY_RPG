/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Item randomizer
*/

#include "my_rpg.h"

int get_type(int min)
{
    int type = randnb(min, 100);

    if (type <= 30)
        return AMMO;
    if (type > 30 && type <= 90)
        return AMMO;
    if (type > 90 && type <= 100)
        return WEAPON;
    return (0);
}

int get_rarity(void)
{
    int rarity = randnb(0, 24);

    if (rarity <= 12)
        return COMMON;
    if (rarity > 12 && rarity <= 17)
        return RARE;
    if (rarity > 17 && rarity <= 22)
        return EPIC;
    if (rarity > 22)
        return LEGENDARY;
    return (0);
}

int get_ammo_type(void)
{
    int ammo = randnb(0, 100);
    if (ammo <= 30)
        return LIGHTAMMO;
    if (ammo > 30 && ammo <= 50)
        return MEDIUMAMMO;
    if (ammo > 50 && ammo <= 70)
        return HEAVYAMMO;
    if (ammo > 70 && ammo <= 95)
        return EXPLOSIVEAMMO;
    if (ammo > 95 && ammo <= 100)
        return SPECIALAMMO;
    return (0);
}

int get_weapon_type(void)
{
    int weapon = randnb(0, 100);

    if (weapon <= 24)
        return PISTOL;
    if (weapon > 24 && weapon <= 49)
        return SMG;
    if (weapon > 49 && weapon <= 69)
        return RIFLE;
    if (weapon > 69 && weapon <= 84)
        return SHOTGUN;
    if (weapon > 84 && weapon <= 89)
        return SNIPER;
    if (weapon > 89 && weapon <= 94)
        return LMG;
    if (weapon > 94)
        return EXPLOSIVE;
    return (0);
}
