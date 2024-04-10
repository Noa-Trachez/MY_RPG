/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#ifndef WINDOW_H
    #define WINDOW_H

typedef struct {
    int isClickHold;
    sfVector2i oldMousePos;
} camera_t;

typedef struct {
    sfSoundBuffer *buff;
    sfSoundBuffer *buff_achievement;
    sfSound *on_click;
    sfSound *achievement;
    sfMusic *muse;
    sfMusic *menu_music;
} sound_t;

typedef struct {
    int displayCursor;
    sfVector2i size;
    sfVideoMode mode;
    sfRenderWindow *screen;
    sfView *gameView;
    sfView *menuView;
    sfSprite *cursor;
    sfVector2f offset;
    int fullscreen;
    int v_sync;
    int fps;
    int sound;
    int isClickHold;
    sfVector2i oldMousePos;
} window_t;

#endif/*WINDOW_H*/
