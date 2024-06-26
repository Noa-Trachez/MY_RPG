/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** sprite.h
*/

#ifndef SPRITE_H
    #define SPRITE_H

enum BUTTON_E {SETTINGS_BUTTON, SAVE_BUTTON, EXIT_BUTTON, PLAY_BUTTON,
CONTINUE_BUTTON, FPS_30, FPS_60, FPS_144, HTP_ICON, MINUS_ICON, PAUSE_ICON,
PLUS_ICON, SETTINGS_ICON, SW_OFF, SW_ON, EXIT_ICON, HIGH_ICON, LRES, MRES,
HRES, VSINC_ON, VSINC_OFF, QUIT_INVENTORY, VALID_ICON, DELETE_ICON, BIND_ICON,
FULL_OFF, FULL_ON, LEFT_HOW, RIGHT_HOW,};

static const sfIntRect BUTTON_SPRITE[] = {{0, 0, 328, 110},
{328, 0, 328, 110}, {656, 0, 328, 110}, {984, 0, 328, 110},
{1312, 0, 328, 110}, {0, 110, 328, 110}, {328, 110, 328, 110},
{656, 110, 328, 110}, {0, 220, 100, 100}, {100, 220, 100, 100},
{200, 220, 100, 100}, {300, 220, 100, 100}, {400, 220, 100, 100},
{506, 230, 83, 37}, {506, 274, 83, 37}, {0, 320, 100, 100},
{100, 320, 100, 100}, {0, 420, 328, 110}, {328, 420, 328, 110},
{656, 420, 328, 110}, {984, 420, 328, 110}, {1312, 420, 328, 110},
{0, 530, 100, 100}, {100, 542, 96, 77}, {196, 531, 74, 83},
{1200, 320, 100, 100}, {984, 630, 328, 110}, {1312, 630, 328, 110},
{0, 3153, 145, 145}, {145, 3153, 145, 145}};

enum CHARACTER_MOVEMENT {MOVE_RIGHT, MOVE_LEFT, MOVE_UP, MOVE_DOWN};

static const sfIntRect CHARACTER[2][5][10] = {
    { // CHARACTER 1
        { // MOVE RIGHT
            {0, 10, 77, 100},
            {127, 8, 77, 100},
            {255, 9, 77, 100},
            {383, 10, 77, 100},
            {511, 9, 77, 100},
            {639, 8, 77, 100},
            {767, 8, 77, 100},
            {895, 10, 77, 100},
            {1023, 9, 77, 100},
            {0, 0, 0, 0}
        },
        { // MOVE LEFT
            {0, 111, 77, 100},
            {125, 112, 77, 100},
            {253, 111, 77, 100},
            {380, 111, 77, 100},
            {509, 111, 77, 100},
            {637, 112, 77, 100},
            {765, 112, 77, 100},
            {893, 111, 77, 100},
            {1021, 112, 77, 100},
            {0, 0, 0, 0}
        },
        { // MOVE UP
            {0, 213, 80, 100},
            {124, 213, 80, 100},
            {248, 213, 80, 100},
            {373, 213, 80, 100},
            {497, 213, 80, 100},
            {622, 213, 80, 100},
            {0, 0, 0, 0}
        },
        { // MOVE DOWN
            {0, 323, 77, 100},
            {128, 323, 77, 100},
            {259, 323, 77, 100},
            {387, 322, 77, 100},
            {513, 322, 77, 100},
            {642, 322, 77, 100},
            {0, 0, 0, 0}
        },
        { // DIES
            {0, 428, 85, 98},
            {111, 466, 94, 60},
            {239, 466, 94, 60},
            {370, 467, 94, 60},
            {497, 466, 94, 60},
            {623, 467, 105, 59},
            {747, 467, 116, 60},
            {878, 467, 111, 59},
            {0, 0, 0, 0}
        }
    },
    { // CHARACTER 2
        {},
        {},
        {},
        {},
        {}
    }
};
#endif/*SPRITE_H*/
