/*
** EPITECH PROJECT, 2021
** GLOBALS_METHODS
** File description:
** todo: Description
*/

int get_global(int (*f)())
{
    return (f(0, 0));
}

int set_global(int (*f)(), int value)
{
    return (f(value, 1));
}
