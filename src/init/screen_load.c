/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** screen_load.c
*/

#include "my_rpg.h"

long long int count_nblines_nbchar(char *file, int nbline_or_nbchar)
{
    FILE *fd = fopen(file, "r");
    size_t bufsize = 0;
    char *buf = NULL;
    int len = 0;
    long long int nb_char = 0;
    long long int return_getline = 1;

    if (!fd)
        return (-1);
    while (return_getline > 0) {
        return_getline = getline(&buf, &bufsize, fd);
        nb_char += return_getline;
        len++;
    }
    fclose(fd);
    return (nbline_or_nbchar == 0 ? len - 1 : nb_char + 1);
}

void choose_bckg(saves_t *node, int pos, sfVideoMode vmode)
{
    sfTexture *texture = get_interface();
    sfVector2f mode = {(float)vmode.width / 1920, (float)vmode.height / 1080};
    sfVector2f position[3] = {{360, 38}, {811, 38}, {1261, 38}};

    position[pos] = (sfVector2f){position[pos].x * mode.x,
    position[pos].y * mode.y};
    node->background = sfSprite_create();
    sfSprite_setTexture(node->background, texture, 0);
    sfSprite_setTextureRect(node->background, (!node->error) ?
    INTERFACE_SPRITE[IN_SAVED] : INTERFACE_SPRITE[IN_NOT_SAVED]);
    sfSprite_setScale(node->background,
    (sfVector2f){0.9 * mode.x, 0.9 * mode.y});
    sfSprite_setPosition(node->background, position[pos]);
}

void create_sprite_save(saves_t *node, int index, sfVideoMode mode)
{
    sfIntRect rect = {0, 0, 0, 0};
    sfVector2f pos[3] = {{260, 38}, {510, 38}, {765, 38}};

    for (int i = 0; i < 3; i++) {
        pos[i].x *= (float)mode.width / 1066.0;
        pos[i].y *= (float)mode.height / 600.0;
    }
    node->sprite = sfRectangleShape_create();
    sfRectangleShape_setTexture(node->sprite, get_character(), 0);
    sfRectangleShape_setTextureRect(node->sprite, CHARACTER[0][MOVE_DOWN][0]);
    sfRectangleShape_setPosition(node->sprite, pos[index]);
    sfRectangleShape_setSize(node->sprite, (sfVector2f){100, 100});
    sfRectangleShape_setScale(node->sprite,
    (sfVector2f){(float)mode.width / 1066, (float)mode.height / 600});
    rect = sfRectangleShape_getTextureRect(node->sprite);
    sfRectangleShape_setSize(node->sprite,
    (sfVector2f){rect.width, rect.height});
}

char *get_time_played(int time)
{
    int hours = time / 3600;
    int minutes = (time - hours * 3600) / 60;
    int seconds = time - hours * 3600 - minutes * 60;
    char *time_played = int_to_str(hours);
    char *tmp;

    time_played = my_strappend(time_played, ":", 1);
    tmp = int_to_str(minutes);
    if (my_strlen(tmp) < 2)
        time_played = my_strappend(time_played, "0", 1);
    time_played = my_strappend(time_played, tmp, 1);
    free(tmp);
    time_played = my_strappend(time_played, ":", 1);
    tmp = int_to_str(seconds);
    if (my_strlen(tmp) < 2)
        time_played = my_strappend(time_played, "0", 1);
    time_played = my_strappend(time_played, tmp, 1);
    free(tmp);
    return (time_played);
}

void create_text_save(saves_t *node, int index, sfVideoMode mode)
{
    static sfFont *font = NULL;
    char *str = int_to_str(node->percentage);
    char *time_played = get_time_played(node->time_played);
    sfVector2f pos[3] = {{260, 300}, {510, 300}, {765, 300}};
    sfVector2f post[3] = {{245, 250}, {495, 250}, {750, 250}};

    for (int i = 0; i < 3; i++) {
        pos[i].x *= (float)mode.width / 1066.0;
        pos[i].y *= (float)mode.height / 600.0;
        post[i].x *= (float)mode.width / 1066.0;
        post[i].y *= (float)mode.height / 600.0;
    }
    if (font == NULL)
        font = sfFont_createFromFile("assets/fonts/Oswald-Bold.ttf");
    str = my_strappend(str, " %", 1);
    node->text = create_text(str, 35 * mode.width / 1066, pos[index]);
    node->time = create_text(time_played, 35 * mode.width / 1066, post[index]);
    sfText_setFont(node->text, font);
    sfText_setFont(node->time, font);
    free(str);
}
