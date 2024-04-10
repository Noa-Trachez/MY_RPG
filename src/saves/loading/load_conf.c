/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Conf loading from .config
*/

#include "my_rpg.h"

void load_bind(int fd, main_t *main)
{
    main->key_code = malloc(sizeof(keycode_t));
    main->key_code->binding = NULL;
    read(fd, &main->key_code->left, sizeof(int));
    read(fd, &main->key_code->up, sizeof(int));
    read(fd, &main->key_code->right, sizeof(int));
    read(fd, &main->key_code->down, sizeof(int));
    read(fd, &main->key_code->interact, sizeof(int));
    read(fd, &main->key_code->inventory, sizeof(int));
    read(fd, &main->key_code->key_to_change, sizeof(int));
}

int load_conf(main_t *main)
{
    long long size_file = my_stat("data/.config", 1);
    int fd = open("data/.config", O_RDONLY);
    int fsv[4];
    sfVector2i size;
    sfVideoMode mode;

    if (fd < 0 || size_file != 36 + (7 * sizeof(int)))
        return (0);
    read(fd, &fsv[0], sizeof(int));
    read(fd, &size, sizeof(sfVector2i));
    read(fd, &mode, sizeof(sfVideoMode));
    read(fd, &fsv[1], sizeof(int));
    read(fd, &fsv[2], sizeof(int));
    read(fd, &fsv[3], sizeof(int));
    load_bind(fd, main);
    init_spe_win(main, fsv, size, mode);
    close(fd);
    return (1);
}
