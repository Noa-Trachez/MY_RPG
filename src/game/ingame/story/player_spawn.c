/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Player spawn (INIT)
*/

#include "my_rpg.h"

static sfRectangleShape *init_step_a(main_t *main, sfRectangleShape *rect)
{
    rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect, sfBlack);
    sfRectangleShape_setRotation(main->game->player->sprite, 90);
    return (rect);
}

static void anim_step_a(main_t *main, story_t *story, int *step)
{
    static sfRectangleShape *rect = NULL;

    if (!rect)
        rect = init_step_a(main, rect);
    sfRenderWindow_setView(main->window->screen, main->window->menuView);
    sfRenderWindow_drawRectangleShape(main->window->screen, rect, 0);
    sfRenderWindow_setView(main->window->screen, main->window->gameView);
    if (sfTime_asSeconds(sfClock_getElapsedTime(story->clock)) < 0.1)
        return;
    sfRectangleShape_setSize(rect, (sfVector2f){main->window->mode.width,
    main->window->mode.height});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0,
    story->fadeColor));
    story->fadeColor -= 5;
    sfClock_restart(story->clock);
    if (story->fadeColor == 0) {
        sfRectangleShape_destroy(rect);
        (*step)++;
    }
}

static void anim_step_b(main_t *main, story_t *story, int *step)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(story->clock)) < 0.01)
        return;
    sfRectangleShape_setRotation(main->game->player->sprite,
    story->playerRotation);
    story->playerRotation -= 4;
    sfClock_restart(story->clock);
    if (story->playerRotation <= 0) {
        sfRectangleShape_setRotation(main->game->player->sprite, 0);
        (*step)++;
    }
}

void player_waking_up(main_t *main)
{
    static int step = 0;
    story_t *story = main->game->story;
    player_t *player = main->game->player;

    if (step == 0)
        anim_step_a(main, story, &step);
    if (step == 1)
        anim_step_b(main, story, &step);
    if (step == 2) {
        story->isStoryDone = 1;
        player->state->canShot = 1;
        player->state->canMove = 1;
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(story->particleClock)) >= 1) {
        new_particle_zzz(&main->particles->zzzParticles,
        (sfVector2f){player->pos.x, player->pos.y - 15});
        sfClock_restart(story->particleClock);
    }
}
