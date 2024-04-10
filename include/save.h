/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#ifndef SAVE_H
    #define SAVE_H

// LOAD MENU INFO
typedef struct saves_s {
    int error;
    float percentage;
    float time_played;
    sfText *text;
    sfText *time;
    sfRectangleShape *sprite;
    sfSprite *background;
    struct saves_s *next;
} saves_t;

// LOAD MENU STRUCT
typedef struct {
    int selectedSave;
    sfRectangleShape *rect;
} loadMenu_t;

#endif/*SAVE_H*/

#ifdef GAME_T
// LOADING
void reload_game(game_t *game);
void load_game(game_t *game, int save_index);
void load_infos(game_t *game, int fd);
void load_player(game_t *game, int fd);
void load_quests(game_t *game, int fd);
void load_npc(game_t *game, int fd);
void load_chests(game_t *game, int fd);
void load_items(game_t *game, int fd);
void load_tp(game_t *game, int fd);
void load_story(game_t *game, int fd);
void get_save_infos(char *save, float *time_played, float *quests_percentage);

// SAVING
void save_game(game_t *game);
void save_infos(game_t *game, int fd);
void save_player(game_t *game, int fd);
void save_quests(game_t *game, int fd);
void save_npc(game_t *game, int fd);
void save_chests(game_t *game, int fd);
void save_item(items_t *items, int fd);
void save_tp(game_t *game, int fd);
void save_story(game_t *game, int fd);
#endif/*GAME_T*/

#ifdef MAIN_T
// LOAD MENU
void goto_load_menu(main_t *main);
void load_menu(main_t *main);
void destroy_load_menu(menu_t *menu, saves_t *saves);
long long int count_nblines_nbchar(char *file, int nbline_or_nbchar);
void choose_bckg(saves_t *node, int pos, sfVideoMode vmode);
void create_sprite_save(saves_t *node, int index, sfVideoMode mode);
char *get_time_played(int time);
void create_text_save(saves_t *node, int index, sfVideoMode mode);

void erase_save(main_t *main);
#endif/*MAIN_T*/
