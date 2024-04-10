/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** quest_builder
*/

#ifndef QUEST_BUILDER_H_
    #define QUEST_BUILDER_H_

    #define UNUSED -1
    #include "items.h"

//TYPES FOR QUESTS
enum QUEST_TYPES {QU_KILLS, QU_MOVE, QU_ZOOM, QU_INVENTORY, QU_QUEST,
QU_ITEM, QU_SPACESHIP, QU_TALK, QU_FIRST_WEAPON, QU_SPECIAL_PIECE,
QU_COPILOT, QU_TUTO, QU_MINER, QU_FARMER, QU_GET_GOLD, QU_DO_GOLD,
QU_GET_METAL, QU_ENTER_ENGINE, QU_SAILOR, QU_SAGE, QU_ARENA};

enum QUESTS_IC {IC_TARGET, IC_SPEED, IC_METAL, IC_MSG, IC_GOLD, IC_ZOOM,
IC_GUN};

static const sfIntRect QUESTS_ICONS[7] = {
    {1908, 0, 61, 61},
    {1974, 0, 77, 57},
    {2051, 0, 59, 60},
    {2115, 0, 68, 66},
    {2183, 0, 73, 66},
    {2664, 0, 66, 67},
    {2330, 4, 55, 63}
};

static const sfVector2f QUESTPOS[] = {
    {290, 200},
    {290, 415},
    {290, 615},
    {290, 820},
};

static const sfIntRect BUTTON_QUEST[] = {
    {200, 145, 650, 155},
    {200, 355, 650, 155},
    {200, 560, 650, 155},
    {200, 765, 650, 155},
};

typedef struct quest_s {
    int accomplish;
    int mandatory;
    int nb;
    int type;
    int item[2];
    int total;
    char *earned;
    sfText *sentence;
    sfText *text;
    sfText *desc;
    sfVector2f scale;
    items_t *getItem;
    sfRectangleShape *sprite;
    struct quest_s *next;
    struct quest_s *prev;
} quest_t;

//============ CREATE A NEW QUEST ============//

/////////////////////////////////////////////////////////
///
/// * Mandatory needed -> 0 = No Mandatory/ 1 = 1 Mandatory -> (int)
/// * Total     ->  of things to be done for quest (int)
/// * Type      ->  for complete quest (int)
/// * Item      ->  Item drop {item->type, weapon->type} (int[2])
/// * Str       ->  Sentence in preview of quests menu (char *)
/// * Desc      ->  Description of the quest when it's selected (char *)
/// * Sentence  ->  Sentence describing state of the quest (char *)
/// * Sprite    ->  Relative path for sprite who illustrate your quest (char *)
/// * Scale     ->  Scale of your sprite (sfVector2f)
///
/////////////////////////////////////////////////////////

// If you need a mandatory for one quest, your mandatory must be done
// to see your quest

typedef struct all_quest_s {
    int mandatory;
    int total;
    int type;
    int item[2];
    char *str;
    char *desc;
    char *sentence;
    sfIntRect rect;
    sfVector2f scale;
} all_quest_t;

static const all_quest_t TAB_QUESTS[] =
{
    {1, 1, QU_QUEST, {UNUSED, UNUSED},
    "New challenger", "Open quests menu",
    "DONE : \t", QUESTS_ICONS[IC_ZOOM],
    (sfVector2f){76, 76}},

    {1, 1, QU_INVENTORY, {UNUSED, UNUSED},
    "Taking inventory", "Press TAB to open inventory ",
    "DONE :\t", QUESTS_ICONS[IC_ZOOM],
    (sfVector2f){76, 76}},

    {1, 1, QU_ZOOM, {UNUSED, UNUSED},
    "Zooooooom !", "Use mouse wheel to zoom\nin and out",
    "DONE :\t", QUESTS_ICONS[IC_ZOOM],
    (sfVector2f){76, 76}},

    {0, 1, QU_MOVE, {UNUSED, UNUSED},
    "Move Around !", "Use ZQSD to move",
    "DONE :\t", QUESTS_ICONS[IC_SPEED],
    (sfVector2f){76, 76}},

    {1, 100, QU_KILLS, {UNUSED, UNUSED},
    "Serial killer !", "Kill 100 ennemies",
    "Killed :\t", QUESTS_ICONS[IC_TARGET],
    (sfVector2f){76, 76}},

    {1, 10, QU_KILLS, {UNUSED, UNUSED},
    "Sharpshooter !", "Kill 10 ennemies",
    "Killed :\t", QUESTS_ICONS[IC_TARGET],
    (sfVector2f){76, 76}},

    {1, 1, QU_KILLS, {UNUSED, UNUSED},
    "Time to strike !", "Kill your first enemy",
    "Killed :\t", QUESTS_ICONS[IC_TARGET],
    (sfVector2f){76, 76}},

    {0, 2, QU_ITEM, {UNUSED, UNUSED},
    "OVERPOWERED !!!", "Equip 2 items !\n\nLeft click on right bar to\n"\
    "select a"\
    " slot where you want\nto equip item.\n\nLeft click on the item\n" \
    "you want"\
    " to equip",
    "Items equiped :\t", QUESTS_ICONS[IC_TARGET],
    (sfVector2f){76, 76}},

    {1, 1, QU_ARENA, {UNUSED, UNUSED},
    "Let s FIGHT !", "Go to the arena in the south",
    "DONE : \t", QUESTS_ICONS[IC_TARGET],
    (sfVector2f){76, 76}},

    {1, 1, QU_SAGE, {WEAPON, LMG},
    "Go to the sage!", "Go and talk to the sage",
    "DONE : \t", QUESTS_ICONS[IC_MSG],
    (sfVector2f){76, 76}},

    {1, 1, QU_SAILOR, {UNUSED, UNUSED},
    "Go to the sailor!", "Go and talk to the sailor",
    "DONE : \t", QUESTS_ICONS[IC_MSG],
    (sfVector2f){76, 76}},

    {1, 1, QU_ENTER_ENGINE, {UNUSED, UNUSED},
    "Go to the mechanic!", "Go and talk to the mechanic",
    "DONE : \t", QUESTS_ICONS[IC_MSG],
    (sfVector2f){76, 76}},

    {1, 1, QU_GET_METAL, {IRON, ID_IRON},
    "Get your metal !", "Go back to the miner\nto get the metal",
    "DONE : \t", QUESTS_ICONS[IC_MSG],
    (sfVector2f){76, 76}},

    {1, 1, QU_GET_GOLD, {INGOTS, ID_INGOTS},
    "Get your gold !", "Go back to the farmer\nto get the gold",
    "DONE : \t", QUESTS_ICONS[IC_GOLD],
    (sfVector2f){76, 76}},

    {1, 10, QU_DO_GOLD, {UNUSED, UNUSED},
    "Kill 10 monstres", "Kill 10 ennemies\nto get the gold",
    "DONE : \t", QUESTS_ICONS[IC_TARGET],
    (sfVector2f){76, 76}},

    {1, 1, QU_FARMER, {UNUSED, UNUSED},
    "Talk to the farmer", "Try to find your the farmer",
    "DONE : \t", QUESTS_ICONS[IC_MSG],
    (sfVector2f){76, 76}},

    {1, 1, QU_MINER, {UNUSED, UNUSED},
    "Talk to the miner", "Try to find your the miner",
    "DONE : \t", QUESTS_ICONS[IC_MSG],
    (sfVector2f){76, 76}},

    {1, 1, QU_COPILOT, {UNUSED, UNUSED},
    "Old Friends", "Try to find your old friend",
    "DONE : \t", QUESTS_ICONS[IC_MSG],
    (sfVector2f){76, 76}},

    {1, 1, QU_TUTO, {UNUSED, UNUSED},
    "Finish Tuto", "Talking with the guide",
    "DONE : \t", QUESTS_ICONS[IC_MSG],
    (sfVector2f){76, 76}},

    {1, 1, QU_FIRST_WEAPON, {UNUSED, UNUSED},
    "Pick up the gun !", "You have to go pick up the gun\n",
    "DONE :\t", QUESTS_ICONS[IC_TARGET],
    (sfVector2f){76, 76}},

    {0, 1, QU_TALK, {UNUSED, UNUSED},
    "Talk !", "Start by speaking with the NPC",
    "DONE :\t", QUESTS_ICONS[IC_MSG],
    (sfVector2f){76, 76}},

    {0, 0, 0, {0, 0}, NULL, NULL, NULL, {0, 0, 0, 0}, {0, 0}}
};

quest_t *new_quest(quest_t *quest, all_quest_t tab);

// QUEST DISPLAYER
typedef struct questHud_s {
    int toBeDestroyed;
    int state;
    int opacity;
    sfRectangleShape *rect;
    sfText *text;
    sfClock *clock;
    struct questHud_s *next;
} quest_hud_t;

// BUILDER
void add_quest_popup(quest_hud_t **quest_popup, char *str);
void destroy_quest_popup(quest_hud_t **quest_popup);
items_t *build_item_quest(quest_t *quest);

#endif/* !QUEST_BUILDER_H_ */

#ifdef MAIN_T

// STATE
void display_quest_hud(quest_hud_t *quest_hud, window_t *window, main_t *main);
void update_quest_hud(quest_hud_t *quest_hud, sfVector2f mode, sound_t *sound);

// DISPLAY
void quest_manager(main_t *main);
void resize_quests(main_t *main);
void resize_quests_manager(main_t *main, sfSprite *sprite, sfText *desc);
void resize_quest_desc(main_t *main, quest_t *quest);
void draw_desc(main_t *main, int i);

// COMLPLETE_QUESTS
int get_goals(main_t *main, int type);

// MOUSE_ON_QUESTS
sfIntRect resize_mouse_rect(window_t *window, sfIntRect rect);
void is_mouse_on_quest(main_t *main);

// CHECK
int check_quest(main_t *main, int type);
int check_quest_complete(main_t *main,  __attribute__((unused))npc_t *npc,
const int args[2]);
#endif/*MAIN_T*/
