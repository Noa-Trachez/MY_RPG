/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Main file of the project
*/

#include "my_rpg.h"

int main(int ac, __attribute__((unused))char **av)
{
    if (ac > 1) {
        write(2, "Too many arguments\n", 19);
        return (84);
    }
    if (check_assets()) {
        write(2, "Corrupted files\n", 16);

        return (84);
    }
    my_rpg();
    return (0);
}
