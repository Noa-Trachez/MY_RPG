/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Goto load menu
*/

#include "my_rpg.h"

void init_nodes_values(saves_t **node)
{
    (*node)->next = NULL;
    (*node)->percentage = 0;
    (*node)->time_played = 0;
    (*node)->time = NULL;
    (*node)->sprite = NULL;
    (*node)->text = NULL;
}

saves_t *nodes_of_saves(char *name_save, int pos, sfVideoMode mode)
{
    int fd = open(name_save, O_RDONLY);
    saves_t *node = malloc(sizeof(saves_t));

    node->error = (count_nblines_nbchar(name_save, 1) < 8) ? 1 : 0;
    init_nodes_values(&node);
    if (node->error) {
        choose_bckg(node, pos, mode);
        if (fd >= 0)
            close(fd);
        return (node);
    }
    get_save_infos(name_save, &node->time_played, &node->percentage);
    choose_bckg(node, pos, mode);
    create_sprite_save(node, pos, mode);
    create_text_save(node, pos, mode);
    return (node);
}

void append_nodes_save(saves_t **save, char *name_save, int pos,
sfVideoMode mode)
{
    saves_t *tmp = *save;

    if (!(*save)) {
        *save = nodes_of_saves(name_save, pos, mode);
        return;
    }
    while ((*save)->next)
        *save = (*save)->next;
    (*save)->next = nodes_of_saves(name_save, pos, mode);
    *save = tmp;
}

void create_load_menu(loadMenu_t *load_menu, window_t *window)
{
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};

    load_menu->selectedSave = 0;
    load_menu->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(load_menu->rect,
    (sfVector2f){360 * mode.x, 38 * mode.y});
    sfRectangleShape_setSize(load_menu->rect,
    (sfVector2f){360 * mode.x, 628 * mode.y});
    sfRectangleShape_setFillColor(load_menu->rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(load_menu->rect, 6);
    sfRectangleShape_setOutlineColor(load_menu->rect, sfWhite);
}

void goto_load_menu(main_t *main)
{
    char *name_saves[] = {"data/save1", "data/save2", "data/save3"};

    main->saves = NULL;
    for (int i = 0; i < 3; i++)
        append_nodes_save(&main->saves, name_saves[i], i, main->window->mode);
    main->menu->loadMenu = malloc(sizeof(loadMenu_t));
    create_load_menu(main->menu->loadMenu, main->window);
    main->scene = LOAD_MENU;
}
