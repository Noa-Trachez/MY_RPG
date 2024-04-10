/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Map switching
*/

#include "my_rpg.h"

void delete_obstacles(obstacle_t **obstacles)
{
    obstacle_t *save = NULL;

    while (*obstacles) {
        save = (*obstacles)->next;
        free(*obstacles);
        *obstacles = save;
    }
    *obstacles = NULL;
}

void clear_pathfinding_grid(map_t *map)
{
    if (map && map->pathfinder) {
        for (int y = 0; y < map->mapsize.y; y++)
            free(map->pathfinder[y]);
        free(map->pathfinder);
    }
}

void set_map_texture(map_t *map, int mapno)
{
    static sfTexture *map_texture = NULL;
    sfIntRect mapr;

    if (map_texture != NULL) {
        sfTexture_destroy(map_texture);
        sfSprite_destroy(map->map);
    }
    map->currentMap = mapno;
    map_texture = sfTexture_createFromFile(MAPS[mapno * 2], 0);
    map->map = sfSprite_create();
    sfSprite_setTexture(map->map, map_texture, 1);
    mapr = sfSprite_getTextureRect(map->map);
    sfSprite_setOrigin(map->map,
    (sfVector2f){mapr.width / 2, mapr.height / 2});
    sfSprite_setPosition(map->map, (sfVector2f){0, 0});
    sfSprite_setScale(map->map, (sfVector2f){2, 2});
}

void switch_map(map_t *map, game_t *game, int mapno)
{
    set_map_texture(map, mapno);
    delete_obstacles(&map->obstacles);
    clear_pathfinding_grid(map);
    load_map(map, MAPS[mapno * 2 + 1]);
    init_pathfinding_grid(map);
    add_collide_npc(map, game->npc, map->currentMap);
    add_collide_chest(map, game->chest, map->currentMap);
    add_collide_doors(map, game->doors, map->currentMap);
}
