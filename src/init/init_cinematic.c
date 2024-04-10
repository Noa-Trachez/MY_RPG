/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** INIT Cinematic scene
*/

#include "my_rpg.h"

sfSprite *create_sprite_cinematic(int i)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, get_cin(), sfTrue);
    sfSprite_setTextureRect(sprite, RECT_CIN[i]);
    return sprite;
}

sfSprite **add_background(void)
{
    sfSprite **background = malloc(sizeof(sfSprite *) * 4);
    background[0] = sprite_inventory_create("assets/space_back/0.png",
    (sfVector2f){0, 0}, (sfVector2f){1, 1});
    background[1] = sprite_paralax("assets/space_back/1.png",
    (sfVector2f){0, 0}, (sfVector2f){1, 1});
    background[2] = sprite_paralax("assets/space_back/2.png",
    (sfVector2f){0, 0}, (sfVector2f){1, 1});
    background[3] = NULL;
    return background;
}

cinematic_t *add_scene(cinematic_t *cin_head, char const *subtitle, int scene)
{
    cinematic_t *new_cin = malloc(sizeof(cinematic_t));
    new_cin->image = create_sprite_cinematic(0);
    new_cin->planet = create_sprite_cinematic(1);
    sfSprite_setOrigin(new_cin->image, (sfVector2f){622, 332});
    new_cin->subtitle = create_text(subtitle, 30,
    (sfVector2f){750, 800});
    new_cin->next = cin_head;
    new_cin->next_clock = sfClock_create();
    new_cin->anim_clock = sfClock_create();
    new_cin->map_clock = sfClock_create();
    new_cin->go_next = 0;
    new_cin->start = 1;
    new_cin->scene = scene;
    new_cin->prev = NULL;
    if (cin_head != NULL)
        cin_head->prev = new_cin;
    return new_cin;
}

void init_cinematic(main_t *main)
{
    main->cinematic = NULL;
    main->clock_cin = sfClock_create();
    main->background = add_background();
    for (int i = 0; SUB[i] != NULL; i++)
        main->cinematic = add_scene(main->cinematic, SUB[i], i);
    for (; main->cinematic->next != NULL;
    main->cinematic = main->cinematic->next);
}
