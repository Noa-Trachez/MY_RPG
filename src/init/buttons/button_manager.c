/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** INIT Buttons
*/

#include "my_rpg.h"

void build_menu_button(main_t *main)
{
    sfVector2f mode = {(float)main->window->mode.width / 1920,
    (float)main->window->mode.height / 1080};
    int height[4] =
    {main->window->mode.width / 2, main->window->mode.width / 2,
    main->window->mode.width / 2, main->window->mode.width / 1.1};
    int width[4] = {main->window->mode.height / 4.2,
    main->window->mode.height / 2, main->window->mode.height / 1.3,
    main->window->mode.height / 7};
    int maccro[4] = {PLAY_BUTTON, SETTINGS_BUTTON,
    EXIT_BUTTON, HTP_ICON};
    void *fun[4] = {&goto_load_menu, &goto_settings, &exit_function,
    &goto_how};

    for (int i = 0; i < 4; i++)
        build_button(&main->buttons, "srpf", MAIN_MENU,
        BUTTON_SPRITE[maccro[i]], (sfVector2f){height[i], width[i]}, fun[i]);
    button_how_to_play(mode, main);
}

void second_part_of_build_settings_button(main_t *main)
{
    int rect_pos = 0;

    if (main->window->mode.width == 1920)
        rect_pos = MRES;
    else if (main->window->mode.width == 1066)
        rect_pos = LRES;
    else
        rect_pos = HRES;
    build_button(&main->buttons, "srpf", SETTINGS_MENU,
    BUTTON_SPRITE[rect_pos], (sfVector2f){main->window->mode.width / 2,
    main->window->mode.height / 8}, &change_scale_window);
    if (main->window->fps == 144)
        rect_pos = FPS_144;
    else if (main->window->fps == 60)
        rect_pos = FPS_60;
    else
        rect_pos = FPS_30;
    build_button(&main->buttons, "srpf", SETTINGS_MENU,
    BUTTON_SPRITE[rect_pos], (sfVector2f){main->window->mode.width / 2,
    main->window->mode.height / 2.5}, &change_fps);
}

void build_settings_button(main_t *main)
{
    int width[4] = {main->window->mode.width / 1.1, main->window->mode.width /
    1.5, main->window->mode.width / 3, main->window->mode.width / 12};
    int height[4] = {main->window->mode.height / 7, main->window->mode.height /
    1.55, main->window->mode.height / 1.55, main->window->mode.height / 7};
    void *fun[4] = {&goto_menu, &volume_up, &volume_down, &goto_bind};
    int maccro[4] = {EXIT_ICON, PLUS_ICON, MINUS_ICON, BIND_ICON};

    for (int i = 0; i < 4; i++)
        build_button(&main->buttons, "srpf", SETTINGS_MENU,
        BUTTON_SPRITE[maccro[i]], (sfVector2f){width[i], height[i]}, fun[i]);
    build_button(&main->buttons, "srpf", SETTINGS_MENU,
    BUTTON_SPRITE[main->window->v_sync ? VSINC_ON : VSINC_OFF],
    (sfVector2f){main->window->mode.width / 1.5,
    main->window->mode.height / 1.2}, &toggle_vsync);
    build_button(&main->buttons, "srpf", SETTINGS_MENU,
    BUTTON_SPRITE[main->window->fullscreen ? FULL_ON : FULL_OFF],
    (sfVector2f){main->window->mode.width / 3,
    main->window->mode.height / 1.2}, &full_screen);
    second_part_of_build_settings_button(main);
}

void build_button_load(main_t *main)
{
    build_button(&main->buttons, "srpf", LOAD_MENU,
    BUTTON_SPRITE[PLAY_BUTTON],
    (sfVector2f){main->window->mode.width / 1.3,
    main->window->mode.height / 1.2}, &goto_ingame);
    build_button(&main->buttons, "srpf", LOAD_MENU,
    BUTTON_SPRITE[DELETE_ICON],
    (sfVector2f){main->window->mode.width / 7,
    main->window->mode.height / 1.2}, &erase_save);
}

void button_manager(main_t *main)
{
    main->buttons = NULL;
    build_menu_button(main);
    build_settings_button(main);
    build_binding_button(main);
    build_button_load(main);
    build_pause_button(main);
    if (main->window->mode.width == 1066)
        scale_all_buttons(main, 1);
    else if (main->window->mode.width == 1920)
        scale_all_buttons(main, 1920.0 / 1066);
    else
        scale_all_buttons(main, 2560.0 / 1066);
}
