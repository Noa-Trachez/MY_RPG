/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** INIT NPCs
*/

#include "my_rpg.h"

void add_collide_npc(map_t *map, npc_t *npc, int current_map)
{
    int i = 0;
    npc_t *head = npc;
    sfVector2f array_pos;

    while (head) {
        array_pos = (sfVector2f){(SPECS_NPC[i].pos.x / map->tilesize.x +
        (float)(map->mapsize.x / 2)), (SPECS_NPC[i].pos.y / map->tilesize.y +
        (float)(map->mapsize.y / 2))};
        if (head->map == current_map && is_in_map(array_pos, map->mapsize)) {
            new_obstacle(&map->obstacles, array_pos,
            (sfFloatRect){(array_pos.x - (float)map->mapsize.x / 2) *
            map->tilesize.x, (array_pos.y - (float)map->mapsize.y / 2) *
            map->tilesize.y, map->tilesize.x, map->tilesize.y});
        }
        i++;
        head = head->next;
    }
}

void init_npc(main_t *main)
{
    main->game->npc = NULL;
    npc_t *npc = NULL;

    for (int i = 0; SPECS_NPC[i].map != END; i++) {
        main->game->npc = new_npc(main->game->npc, SPECS_NPC[i], DISCUSS[i]);
        if (i == 0)
            npc = main->game->npc;
    }
    main->game->npc = npc;
}
