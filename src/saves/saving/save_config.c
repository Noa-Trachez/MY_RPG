/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Conf saving in .config
*/

#include "my_rpg.h"

void save_bind(int fd, keycode_t *key)
{
    write(fd, &key->left, sizeof(int));
    write(fd, &key->up, sizeof(int));
    write(fd, &key->right, sizeof(int));
    write(fd, &key->down, sizeof(int));
    write(fd, &key->interact, sizeof(int));
    write(fd, &key->inventory, sizeof(int));
    write(fd, &key->key_to_change, sizeof(int));
}

void init_spe_win(main_t *main, int *fsv, sfVector2i size, sfVideoMode mode)
{
    main->window->fps = fsv[0];
    main->window->size = size;
    main->window->mode = mode;
    main->window->v_sync = fsv[1];
    main->window->sound = fsv[2];
    main->window->fullscreen = fsv[3];
}

void save_conf(main_t *main)
{
    int fd = open("data/.config", O_CREAT | O_TRUNC | O_WRONLY, 0664);

    if (fd < 0) {
        write(2, "Error: Can't open file\n", 23);
        return;
    }
    write(fd, &main->window->fps, sizeof(int));
    write(fd, &main->window->size, sizeof(sfVector2i));
    write(fd, &main->window->mode, sizeof(sfVideoMode));
    write(fd, &main->window->v_sync, sizeof(int));
    write(fd, &main->window->sound, sizeof(int));
    write(fd, &main->window->fullscreen, sizeof(int));
    save_bind(fd, main->key_code);
    close(fd);
}
