/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** TODO: description
*/

#ifndef BUTTONS_H
    #define BUTTONS_H

/////////////////////////////////////////////////////////
///
/// * Scene     > s     (int)
/// * Rect      > r     (sfIntRect)
/// * Size      > z     (sfVector2f)
/// * Scale     > l     (sfVector2f)
/// * Position  > p     (sfVector2f)
/// * onPressed > f     &f
///
/// > build_button(&buttons_struct, "srzlpf", ...);
///
/////////////////////////////////////////////////////////

    #include "my_rpg.h"

typedef struct buttons {
    int scene;
    int isPressed;
    sfIntRect rect;
    sfVector2f size;
    sfVector2f scale;
    sfVector2f pos;
    sfRectangleShape *sprite;
    int (*onPressed)();
    int isEnable;
    struct buttons *next;
} buttons_t;

// DEFAULT BUTTON
static const buttons_t default_button = {0, 0, (sfIntRect){0, 0, 64, 64},
(sfVector2f){64, 64}, (sfVector2f){1, 1}, (sfVector2f){10, 10},
NULL, NULL, 1, NULL};

// BUILDER
void build_button(buttons_t **buttons, char *parameters, ...);

// SETTER
buttons_t *button_set_rectsh_scene(buttons_t *buttons, va_list list);
buttons_t *button_set_rectsh_rect(buttons_t *buttons, va_list list);
buttons_t *button_set_rectsh_size(buttons_t *buttons, va_list list);
buttons_t *button_set_rectsh_scale(buttons_t *buttons, va_list list);
buttons_t *button_set_rectsh_pos(buttons_t *buttons, va_list list);
buttons_t *button_set_on_pressed(buttons_t *buttons, va_list list);

// STATE
void button_display(window_t *window, buttons_t *buttons, int scene);
void button_is_hovered(buttons_t *buttons, window_t *window, int scene);
void toggle_button(buttons_t *buttons, buttons_t *to_toggle);

// GLOBAL
int g_last_pressed_button(int value, int mod);

#endif/*BUTTONS_H*/

#ifdef MAIN_T
void button_is_pressed(buttons_t *buttons, window_t *window, int scene);
void button_is_released(main_t *main, buttons_t *buttons, window_t *window,
int scene);

#endif/*MAIN_T*/
