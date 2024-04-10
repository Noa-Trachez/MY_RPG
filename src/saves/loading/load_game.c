/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Game loading from save
*/

#include "my_rpg.h"

void load_game(game_t *game, int save_index)
{
    const char saves[3][11] = {"data/save1", "data/save2", "data/save3"};
    int fd = open(saves[save_index], O_CREAT | O_RDONLY, 0664);
    game->player->inventory = NULL;

    if (fd < 0) {
        write(2, "Error: Can't open ", 18);
        write(2, &saves[save_index], 10);
        return;
    }
    load_infos(game, fd);
    read(fd, &game->map->currentMap, sizeof(int));
    load_player(game, fd);
    load_quests(game, fd);
    load_npc(game, fd);
    load_chests(game, fd);
    load_story(game, fd);
    close(fd);
}

void reload_game(game_t *game)
{
    delete_item_list(&game->player->inventory);
    game->player->inventory = NULL;
    for (int i = 0; i < 4; i++)
        game->player->equipedItems->slots[i] = NULL;
    game->player->equipedItems->currentSeclectedItem = 0;
}
