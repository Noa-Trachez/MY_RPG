/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Ingame scene
*/

#include "my_rpg.h"

void draw_hitbox(sfFloatRect rect, sfRenderWindow *window, sfColor color)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setFillColor(shape, color);
    sfRectangleShape_setSize(shape, (sfVector2f){rect.width, rect.height});
    sfRectangleShape_setPosition(shape, (sfVector2f){rect.left, rect.top});
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

void show_hitbox(main_t *main)
{
    obstacle_t *head = main->game->map->obstacles;

    if (!main->debugMode)
        return;
    if (head == NULL)
        return;
    while (head) {
        draw_hitbox(head->obstacle, main->window->screen, sfRed);
        head = head->next;
    }
}

void ingame_looop(main_t *main)
{
    on_ground_item_behaviour(main->game->map, &main->game->onGroundItems,
    main->game->player);
    projectile_behaviour(main->game->player, main->enemies, main->window);
    player_behaviour(main);
    chest_behaviour(main, main->game->chest, &main->game->onGroundItems);
    stat_manager(main);
    quest_manager(main);
    if (main->hud->showLoading)
        loading_icon(main);
    show_hitbox(main);
    if (main->game->story->isStoryDone == 2) {
        cinematic_menu(main);
        cond_effect(main);
    }
    if (!main->game->story->isStoryDone)
        main_story(main);
    boss_fight(main);
    particles_manager(main->particles, main->window);
    sfRenderWindow_setView(main->window->screen, main->window->gameView);
}

void ingame_loop(main_t *main)
{
    sfVector2f array_pos = get_array_pos(main->game->player->pos,
    main->game->map->mapsize, main->game->map->tilesize);

    game_display(main, main->window);
    if (sfTime_asSeconds(sfClock_getElapsedTime(main->gameTick)) < 0.03)
        return;
    door_behaviour(main);
    if (main->game->map->currentMap == 0) {
        spawn_enemy(main, 1, 1, randnb(0, 3));
        enemy_behaviour(main, &main->enemies, main->game->map);
        refresh_paths(main->game->map,
        (int)array_pos.y, (int)array_pos.x, ENEMY_RANGE);
    }
    if (main->hud->fadeState)
        fade_screen(main);
    ingame_looop(main);
}
