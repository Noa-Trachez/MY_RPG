/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#ifndef MY_RPG_H
    #define MY_RPG_H

// BASIC IMPORT
    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <time.h>
    #include <string.h>
    #include <math.h>

// CSFML LIB
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>

// .H IMPORT
    #include "my.h"
    #include "mymaths.h"
    #include "window.h"
    #include "save.h"
    #include "maps.h"
    #include "quest_builder.h"
    #include "npc_builder.h"
    #include "button_builder.h"
    #include "chest_builder.h"
    #include "particles.h"
    #include "hud.h"
    #include "enemy.h"
    #include "player.h"
    #include "projectiles.h"
    #include "items.h"
    #include "cinematic.h"
    #include "sprite.h"
    #include "interface.h"
    #include "how_to_play.h"

    #define MATH_PI 3.141592653589793
    #define ENEMY_RANGE 30

enum menu_e {MAIN_MENU, HTP_MENU, LOAD_MENU, BINDING, PAUSE_MENU, INGAME,
SETTINGS_MENU};

typedef struct {
    sfTexture *screen;
    sfRectangleShape *layer;
    sfSprite *background;
    int pause;
} pause_menu_t;

typedef struct {
    sfSprite *sprite;
} htpMenu_t;

typedef struct {
    sfSprite *background;
    sfText *msg;
    sfFont *fonts;
    loadMenu_t *loadMenu;
    htpMenu_t *htpMenu;
} menu_t;

typedef struct hud {
    int fadeState;
    int showLoading;
    sfCircleShape *loadingCircle[3];
    quest_hud_t *questHud;
    sfRectangleShape *life[2];
} hud_t;

typedef struct info_binding_s {
    sfText *info;
    sfText *key_bind;
    struct info_binding_s *next;
} info_binding_t;

typedef struct {
    int left;
    int up;
    int right;
    int down;
    int interact;
    int inventory;
    int key_to_change;
    info_binding_t *binding;
} keycode_t;

typedef struct {
    int isStoryDone;
    int wokeUp;
    int fadeColor;
    float playerRotation;
    sfClock *clock;
    sfClock *particleClock;
} story_t;

#ifndef GAME_T
    #define GAME_T
typedef struct game_s {
    int currentSave;
    float timePlayedAsSecond;
    sfClock *timePlayed;
    player_t *player;
    story_t *story;
    map_t *map;
    quest_t *quest;
    npc_t *npc;
    chest_t *chest;
    on_ground_items_t *onGroundItems;
    tp_t *tp[6];
    door_t *doors;
} game_t;
#endif/*GAME_T*/

    #ifndef MAIN_T
        #define MAIN_T
typedef struct {
    int random_spawner;
    int scene;
    sfEvent event;
    sfClock *gameTick;
    sfClock *clock_cin;
    cinematic_t *cinematic;
    sfSprite **background;
    sound_t *sound;
    buttons_t *buttons;
    window_t *window;
    menu_t *menu;
    howto_t *howto;
    game_t *game;
    saves_t *saves;
    keycode_t *key_code;
    enemies_t *enemies;
    pause_menu_t *pause_menu;
    particles_t *particles;
    sfClock *enemy_spawner;
    hud_t *hud;
    int debugMode;
    int cin;
} main_t;
        #include "button_builder.h"
        #include "chest_builder.h"
        #include "npc_builder.h"
        #include "enemy.h"
        #include "player.h"
        #include "quest_builder.h"
        #include "hud.h"
        #include "save.h"
        #include "maps.h"
    #endif/*MAIN_T*/

// MAIN
int my_rpg(void);

//CREATOR
sfSprite *create_sprite(char *path, sfVector2f pos, sfVector2f scale);
sfText *create_text(const char *str, int size, sfVector2f pos);

// INIT
int check_assets(void);
void init_window(main_t *main);
void malloc_structs(main_t *main);
void game_init(main_t *main);
void init_quests(main_t *main);
void init_cinematic(main_t *main);
sfSprite *sprite_inventory_create(char *path,
sfVector2f pos, sfVector2f scale);
sfSprite *sprite_paralax(char *path, sfVector2f pos, sfVector2f scale);
void sound_init(main_t *main);
void setup_sound(main_t *main);
void start_music(main_t *main);

// EVENTS
void enter_pressed(main_t *main);
void event_manager(main_t *main);
void ingame_event(main_t *main);
void ingame_mouse_event(main_t *main);
void ingame_interactions(main_t *main);

// LOOP
void game_loop(main_t *main);

// STORY
void init_story(main_t *main);
void main_story(main_t *main);
void player_waking_up(main_t *main);
void boss_fight(main_t *main);
int boss_fight_state(int value, int mod);
void boss_fight_state_a(main_t *main);
void boss_fight_state_b(main_t *main);

//GLOBAL
sfTexture *get_interface(void);
sfTexture *get_npc(void);
sfTexture *get_bkgrnd(void);
sfTexture *get_objects(void);
sfTexture *get_character(void);
sfMusic *get_music(void);
sfMusic *get_menu_music(void);
sfSoundBuffer *get_sound_click(void);
sfSoundBuffer *get_sound_achievement(void);
sfTexture *get_htp(void);
sfTexture *get_cin(void);
sfFont *get_font(void);

// MOUSE EVENT
int is_mouse_on_object(window_t *window, sfVector2f obj_pos, sfVector2f
obj_size, sfVector2f obj_scale);
int is_mouse_on_world_object(window_t *window, sfIntRect object,
sfVector2f obj_pos);
int is_mouse_on_rect(window_t *window, sfIntRect obj);

sfVector2f get_mouse_world_pos(sfRenderWindow *window, sfView *view);

// INGAME
void game_display(main_t *main, window_t *window);
void goto_ingame(main_t *main);
void return_to_game(main_t *main);
void goto_pause(main_t *main);
void destroy_pause_menu(main_t *main);
void ingame_loop(main_t *main);

void camera_move_mouse(main_t *main);
void ingame_zoom(main_t *main);
void reset_view_in_game(main_t *main);
void set_menu_view(main_t *main);

// === INGAME END ===

// MAIN MENU
void main_menu_display(main_t *main);

// PAUSE MENU
void pause_menu_display(main_t *main);

// SETTINGS MENU
void menu_init(main_t *main);
void settings_menu_display(main_t *main);

//HOW TO PLAY
void how_to_play_manager(main_t *main);
void pass_next_scene(main_t *main);
void pass_prev_scene(main_t *main);
void button_how_to_play(sfVector2f mode, main_t *main);
void destroy_htp_menu(main_t *main);

// LOAD
void load_menu_display(main_t *main);
int load_conf(main_t *main);

// SAVE
void save_menu_display(main_t *main);
void save_conf(main_t *main);
long long int my_stat(char *file, int nbline_or_nbchar);
void init_spe_win(main_t *main, int *fsv, sfVector2i size, sfVideoMode mode);

//STATS
void stat_manager(main_t *main);

//CINEMATIC
void cinematic_menu(main_t *main);
void cond_effect(main_t *main);
void anim_planet(main_t *main);
void shake_map(sfSprite *sprite, main_t * main);
void pass_next(main_t *main);
void draw_front_view(main_t *main);
void back_space_display(main_t *main);
void crash_ship(main_t *main);
void delete_particle_cin(main_t *main);

// HTP MENU
void htp_menu_display(main_t *main);

//CHESTS
void init_chests(main_t *main);

//EVENT
void main_menu_event(main_t *main);
void how_to_play_event(main_t *main);
void load_menu_event(main_t *main);
void save_menu_event(main_t *main);
void pause_menu_event(main_t *main);
void cinematic_event(main_t *main);
void settings_menu_event(main_t *main);
void inventory_event(main_t *main);
void how_to_event(main_t *main);
__attribute__((unused)) void game_event(main_t *main);

//button
void build_menu_button(main_t *main);
void button_manager(main_t *main);
void goto_bind(main_t *main);
void build_pause_button(main_t *main);
void exit_function(main_t *main);

//Change resolution
void scale_all_buttons(main_t *main, float size);
void continue_change_resolution(main_t *main, int needed);
void change_scale_window(main_t *main);
void toggle_vsync(main_t *main);
void change_fps(main_t *main);
void change_sprite(main_t *main, sfIntRect to_replace);
void change_bkg(main_t *main);
void full_screen(main_t *main);

//Destroyer
void destroy_button(buttons_t **buttons);

//Sound handling
void volume_down(main_t *main);
void volume_up(main_t *main);
void destroy_sound(main_t *main);
void play_onclick_sound(main_t *main);

//goto
void goto_menu(main_t *main);
void goto_settings(main_t *main);
void goto_how(main_t *main);

//BINDING
void goto_bind(main_t *main);
void set_key_to_change(main_t *main);
void build_binding_button(main_t *main);
info_binding_t *init_nodes(char *str, sfVector2f pos, sfVideoMode mode);
void append_nodes_binding(info_binding_t **binding, char *str, sfVector2f pos,
sfVideoMode mode);
void free_node_binding(info_binding_t **binding);
int get_key_code_index(main_t *main, int index);
void special_keys(main_t *main, int key_code, float diff,
sfVector2f pos);
void create_bind_text(main_t *main, int i, int width, int height);
void load_binding_text(main_t *main);
void change_key_bind(main_t *main);
void error_change_key_bind(main_t *main);
void binding_menu(main_t *main);
void binding_event(main_t *main);
void goto_bind(main_t *main);
#endif/*MY_RPG_H*/
