/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Malloc needed struct
*/

#include "my_rpg.h"

void malloc_other_structs(main_t *main)
{
    main->game->onGroundItems = NULL;
    main->game->timePlayed = sfClock_create();
    main->game->timePlayedAsSecond = 0;
    main->enemy_spawner = sfClock_create();
    main->random_spawner = rand() % 2;
    main->pause_menu = NULL;
    main->debugMode = 0;
    main->cin = 1;
}

void malloc_structs(main_t *main)
{
    main->game = malloc(sizeof(game_t));
    main->game->map = malloc(sizeof(map_t));
    main->howto = malloc(sizeof(howto_t));
    main->howto->scene = 0;
    main->game->map->pathfinder = NULL;
    main->game->map->currentMap = 0;
    main->game->map->obstacles = NULL;
    main->game->player = malloc(sizeof(player_t));
    memset(main->game->player, 0, sizeof(player_t));
    main->particles = malloc(sizeof(particles_t));
    memset(main->particles, 0, sizeof(particles_t));
    main->particles->clock = sfClock_create();
    main->hud = malloc(sizeof(hud_t));
    memset(main->hud, 0, sizeof(hud_t));
    main->menu = malloc(sizeof(menu_t));
    memset(main->menu, 0, sizeof(menu_t));
    main->buttons = NULL;
    main->enemies = NULL;
    malloc_other_structs(main);
}
