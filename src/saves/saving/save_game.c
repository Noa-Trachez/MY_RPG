/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Game saving
*/

#include "my_rpg.h"

void save_game(game_t *game)
{
    const char saves[3][11] = {"data/save1", "data/save2", "data/save3"};
    int fd = open(saves[game->currentSave],
    O_CREAT | O_TRUNC | O_WRONLY, 0664);

    if (fd < 0) {
        write(2, "Error: Can't open ", 18);
        write(2, &saves[game->currentSave], 10);
        return;
    }
    save_infos(game, fd);
    write(fd, &game->map->currentMap, sizeof(int));
    save_player(game, fd);
    save_quests(game, fd);
    save_npc(game, fd);
    save_chests(game, fd);
    save_story(game, fd);
    close(fd);
}

void erase_save(main_t *main)
{
    const char saves[3][11] = {"data/save1", "data/save2", "data/save3"};
    int fd = open(saves[main->menu->loadMenu->selectedSave], O_TRUNC);
    saves_t *head = main->saves;

    close(fd);
    for (int i = 0; head && i < main->menu->loadMenu->selectedSave; i++)
        head = head->next;
    if (head) {
        sfSprite_setTextureRect(head->background,
        INTERFACE_SPRITE[IN_NOT_SAVED]);
        sfText_destroy(head->text);
        head->text = NULL;
        sfText_destroy(head->time);
        head->time = NULL;
        sfRectangleShape_destroy(head->sprite);
        head->sprite = NULL;
    }
}
