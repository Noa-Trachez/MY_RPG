/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** npc_builder
*/

#ifndef NPC_BUILDER_H
    #define NPC_BUILDER_H
    #include "sprite.h"

enum TALKING_STATE {NOT_TALKING, TALKING, TALKED};

typedef struct npc_s {
    int index;
    int selector;
    int isSelected;
    int total;
    sfRectangleShape *sprite;
    sfText *text;
    sfClock *clock;
    sfVector2f pos;
    int map;
    struct npc_s *next;
    struct npc_s *prev;
} npc_t;

typedef struct {
    int map;
    sfIntRect rect;
    sfVector2f pos;
}spec_t;

//NPC'S SPECS
static const spec_t SPECS_NPC[12] =
{
    {MAP, {487, 354, 17, 24}, {2168, -864}}, // MAIN NPC
    {MAP, {38, 5, 17, 23}, {-2160, -8}}, // COPILOT
    {MAP, {299, 69, 16, 24}, {5568, 3440}}, // NINJA IN FRONT OF ARENA
    {MAP, {296, 491, 19, 26}, {4856, -1544}}, // FARMER
    {MAP, {264, 37, 19, 23}, {-4476, 6016}}, // EXPLORER
    {MAP, {264, 178, 21, 25}, {832, -2592}}, // SAILOR
    {MAP, {105, 68, 17, 24}, {1352, -5424}}, // FISHERMAN
    {MAP, {423, 148, 16, 23}, {-3616, -5416}}, // SAGE
    {ENGINE_ROOM, {487, 354, 17, 24}, {-68, -844}}, // HALL
    {ENGINE_ROOM, {487, 354, 17, 24}, {-48, -600}}, // ENGINE_ROOM
    {SPACESHIP, {453, 37, 18, 24}, {-32, -730}}, // PILOT
    {END, {END, END, END, END}, {END, END}},
};

typedef struct action_s{
    int f_check[11];
    int f_exe[11][5];
    int args_check[11][2];
    int args_exe[11][3];
}action_t;

// ============ ACTIONS FOR NPC'S ========== //

/////////////////////////////////////////////////////////
///
/// * f_check[selector]  -> index in the pointer array on check functions (int)
/// * f_exe[selector][i] -> index in the pointer array on exec functions (int)
/// * args_check[selector] -> args for check functions (int[2])
/// * args_exe[selector] -> args for exec functions (int)
///
/////////////////////////////////////////////////////////

static const action_t ACTION[11] =
{
    // ============= MAIN_NPC =============
    {
        {0, 1, 0, 0},
        {
            {5, 1, 0, -1}, // DROP PISTOL
            {1, 0, -1}, // CHECK FIRST WEAPON
            {6, 0, -1}, // DROP LIGHT AMMO
            {1, -1}, // COMPLETE QUEST FIRST WEAPON
        },

        {
            {0, 0},
            {FIRST_WEAPON, -1},
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 10},
            {0, 0},
            {0, 0},
            {0, 0},
        },

        {
            {PISTOL, QU_TALK, UNUSED},
            {QU_FIRST_WEAPON, UNUSED, UNUSED},
            {LIGHTAMMO, UNUSED, UNUSED},
            {QU_TUTO, UNUSED, UNUSED},
        }
    },

    // ============= COPILOT_NPC =============
    {
        {3, 0, 3, 0, 2, 0, 0},
        {
            {0, -1},
            {1, 0, -1},
            {0, -1},
            {2, 0, -1},
            {3, 0, -1},
            {0, -1},
            {-1}
        },

        {
            {QU_TUTO, 0},
            {0, 0},
            {QU_GET_METAL, 0},
            {0, 0},
            {10},
            {0, 0},
            {0, 0}
        },

        {
            {UNUSED, UNUSED, UNUSED},
            {QU_COPILOT, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {1, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
        }
    },

    // ============= NINJA_NPC =============
    {
        {3, 0},
        {
            {0, -1},
            {0, -1},
            {-1}
        },

        {
            {QU_SAGE, 0},
            {0, 0}
        },

        {
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
        }
    },

    // ============= FARMER_NPC =============
    {
        {3, 0, 3, 0, 0},
        {
            {0, -1},
            {1, 0, -1},
            {1, 0, -1},
            {1, 0, -1},
            {-1}
        },

        {
            {QU_MINER, 0},
            {0, 0},
            {QU_DO_GOLD, 0},
            {0, 0},
            {0, 0}
        },

        {
            {UNUSED, UNUSED, UNUSED},
            {QU_FARMER, UNUSED, UNUSED},
            {QU_GET_GOLD, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
        }
    },

    // ============= EXPLORER_NPC =============
    {
        {3, 0, 1, 0, 0},
        {
            {0, -1},
            {1, 0, -1},
            {7, 1, 0, -1},
            {0, -1},
            {-1}
        },

        {
            {QU_COPILOT, 0},
            {QU_MINER, 0},
            {ID_INGOTS, 1},
            {0, 0}
        },

        {
            {UNUSED, UNUSED, UNUSED},
            {QU_MINER, UNUSED, UNUSED},
            {ID_INGOTS, QU_GET_METAL, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
        }
    },

    // ============= SAILOR_NPC =============
    {
        {3, 0, 0, 0, 0},
        {
            {0, -1},
            {1, 0, -1},
            {-1}
        },

        {
            {QU_ENTER_ENGINE, 0},
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0}
        },

        {
            {UNUSED, UNUSED, UNUSED},
            {QU_SAILOR, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
        }
    },

    // ============= FISHERMAN_NPC =============
    {
        {0, 0, 0, 0, 0},
        {
            {0, -1},
            {0, -1},
            {0, -1},
            {0, -1},
            {-1}
        },

        {
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0}
        },

        {
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
        }
    },

    // ============= SAGE_NPC =============
    {
        {3, 0, 0, 0, 0},
        {
            {0, -1},
            {1, 4, 0, -1},
            {0, -1},
            {0, -1},
            {-1}
        },

        {
            {QU_SAILOR, 0},
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0}
        },

        {
            {UNUSED, UNUSED, UNUSED},
            {QU_SAGE, DOOR_ARENA, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
        }
    },

    // ============= HALL_NPC =============
    {
        {0, 0, 0, 0, 0},
        {
            {0, -1},
            {0, -1},
            {0, -1},
            {0, -1},
            {-1}
        },

        {
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0},
            {0, 0}
        },

        {
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
        }
    },

    // ============= ENGINE_NPC =============
    {
        {0, 1, 0, 0, 0},
        {
            {1, 0, -1},
            {3, 3, 4, 0, -1},
            {0, -1},
            {0, -1},
            {-1}
        },

        {
            {0, 0},
            {ID_URANIUM, 1},
            {0, 0},
            {0, 0},
            {0, 0}
        },

        {
            {QU_ENTER_ENGINE, UNUSED, UNUSED},
            {1, 0, DOOR_ENGINE_ROOM},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
        }
    },

    // ============= PILOT_NPC =============
    {
        {0, 0, 0, 0, 0},
        {
            {8, 0, -1},
            {0, -1},
            {0, -1},
            {0, -1},
            {-1}
        },

        {
            {0, 0},
            {0, 1},
            {0, 0},
            {0, 0},
            {0, 0}
        },

        {
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
            {UNUSED, UNUSED, UNUSED},
        }
    },
};

// ============ DISCUSS FOR NPC'S ========== //

// [YOUR NPC][NPC->SELECTOR][NPC->INDEX]

/////////////////////////////////////////////////////////
///
/// * NPC->SELECTOR is the discussion selector of the NPC (int)
/// * NPC->INDEX is the current sentence of the NPC (int)
///
/////////////////////////////////////////////////////////

__attribute__((unused))static const char *DISCUSS[12][11][9] =
{
    // ============= MAIN NPC =============
    {
        {
            "Hello",
            "your spaceship is in very bad condition",
            "It needs to be fixed",
            "On this planet you will have the\nopportunity to find chests",
            "In these chests you can have weapons or\nammunitions",
            "There are many mystical creatures\naround the weapons will be ",
            "used to kill them",
            "Here, I have something for you",
            NULL
        },

        {
            "Go get the gun",
            NULL
        },

        {
            "Good play, you just got your very\nfirst gun",
            "Go ahead, take the ammunitions\nit could be very useful",
            NULL
        },

        {
            "You are welcome",
            NULL
        },

        {
            NULL
        },

    },

    // ============= COPILOT_NPC =============
    {
        {
            "It's dangerous here, you\nshould go and see the teacher",
            NULL
        },

        {
            "Hi, I think our ship is in very bad shape,\nI did a little " \
            "tour of the city\nand I understand that with some\n" \
            "metal we could fix it",
            "I think you should try to look around,\n" \
            "I think there are metal miners\nin the mountains",
            "According to my expertise,\n10 metals should be enough\n" \
            "to repair the main door",
            NULL
        },

        {
            "Come back to me when\nyou have the metal",
            NULL
        },

        {
            "Well done, you got the metal,\nnow let me fix the ship",
            NULL
        },

        {
            "I am currently working,\ncome back to see me later",
            NULL
        },

        {
            "It's OK, everything is fixed\n",
            NULL
        },

        {
            NULL
        },
    },

    // ============= NINJA_NPC =============
    {
        {
            "Speak to the sage first !",
            NULL
        },

        {
            "Hello traveller !\n" \
            "Be careful ! This thing is stronger\nthan you think",
            "Be sure to have the required\nequipment ! And remember...",
            "I'll Never gonna give you up\n" \
            "Never gonna let you down\n" \
            "Oops.. I mean, GOOD LUCK !",
            NULL
        },

        {
            NULL
        }
    },

    // ============= FARMER_NPC =============
    {
        {
            "Don't go near my fields,\ngo back to where you came\nfrom",
            NULL
        },

        {
            "Are you here for gold?",
            "I have some in my stash but\nI don't give anything away\nfor" \
            "free.",
            "If you hunt 10 monsters then\nI will give you some",
            NULL
        },

        {
            "Hurry up and kill them\nall if you want your gold",
            NULL
        },

        {
            "Thank you for protecting my fields\n, that's what I owe you",
            NULL
        },

        {
            NULL
        },
    },

    // ============= EXPLORER_NPC =============
    {
        {
            "What are you doing here, kid?\nYou don't belong here",
            NULL
        },

        {
            "Are you the one looking\nfor metal at all costs?",
            "I can give you some of it if\nyou want, but I'll need\ngold" \
            "in exchange",
            "If I were you I'd try\nto talk to the farmer,\nhe probably " \
            "has a stash of gold\nat home",
            NULL
        },

        {
            "What do you want me to\ntrade you? You have no gold",
            NULL
        },

        {
            "Thanks for the gold,\nhold the metal I owe you",
            NULL
        },

        {
            NULL
        },
    },

    // ============= SAILOR_NPC =============
    {
        {
            "I have nothing to say to\nyou at the moment sailor",
            NULL
        },

        {
            "Hi Sailor, I guess you're coming\nto me to find out how I got" \
            "\nto see the uranium source",
            "Indeed, I have already seen it,\nbut it is thanks to one\n" \
            "and only one person",
            "If you continue on your way,\nyou may have the chance\n" \
            "to meet her",
            NULL
        },

        {
            NULL
        },
    },

    // ============= FISHERMAN_NPC =============
    {
        {
            "I caught a carp today",
            NULL
        },

        {
            NULL
        },
    },

    // ============= SAGE_NPC =============
    {
        {
            "Hmmmmmmmmmm",
            NULL
        },

        {
            "Hmmmmmmmmmm",
            "Good morning young man\nyou have travelled far and\nwide " \
            "to get here, I hear you are\nlooking for a source of uranium.\n",
            "I can help you in your quest\nthanks to my supreme power\n" \
            "I can open the doors to the\ncursed arena.",
            "The monster is incredibly strong\nyou will probably need this",
            NULL
        },

        {
            "I opened the door to the\ncursed arena",
            NULL
        },

        {
            NULL
        },
    },

    // ============= HALL_NPC =============
    {
        {
            "Hi my friend, how are you",
            NULL
        },

        {
            NULL
        },
    },

    // ============= ENGINE_NPC =============
    {
        {
            "Hello I'm the mechanic, unfortunately\nyou can't take off with" \
            "\nengines in this condition",
            "A source of uranium is needed\nto restart the machines",
            "I don't know where you can\nfind them but I know that a\nsailor" \
            " who is usually by\nthe sea has seen them once\nin his life",
            NULL
        },

        {
            "You don't have the uranium\nsource with you",
            NULL
        },

        {
            "Well done, that's exactly\nwhat I needed to power all\n" \
            "the engines",
            "Go to the captain and\ntell him it's okay",
            NULL
        },

        {
            NULL
        },
    },

    // ============= PILOT_NPC =============
    {
        {
            "Hello I m the pilot",
            "We are going to take off\nfasten your seatbelt",
            NULL
        },

        {
            NULL
        },
    },

    // ============= NULL =============
    {
        {
            NULL
        }
    }
};

// BUILDER
npc_t *new_npc(npc_t *npc, spec_t spec, const char *talk[7][9]);

// DISPLAY
void npc_display(npc_t *npc, window_t *window, int current_map);
void resize_npc(window_t *window, npc_t *npc);
#endif/*NPC_BUILDER*/

#ifdef MAIN_T
// INIT_npc
void init_npc(main_t *main);

// COLLIDE
void add_collide_npc(map_t *map, npc_t *npc, int current_map);

// ACTIONS
void handle_npc(main_t *main, player_t *player);
void npc_check(main_t *main, npc_t *npc, int i);
int launch_end(main_t *main);

// CHECK
int pass(main_t *main, npc_t *npc);
int check_object(main_t *main, __attribute__((unused))npc_t *npc,
const int args[2]);
int check_clock(__attribute__((unused))main_t *main, npc_t *npc,
const int args[2]);

// EXEC
int continue_discuss(main_t *main, __attribute__((unused))int args,
npc_t *npc);
int start_clock(__attribute((unused))main_t *main,
__attribute((unused))int args, npc_t *npc);
int toggle_tp(main_t *main, int args);
int drop_npc_weapon(main_t *main, int weapon);
int drop_npc_ammo(main_t *main, int type);
int depop_inventory(main_t *main, int id);

// GET_CURRENT_NPC_SELECTED
int get_current_npc(main_t *main);
#endif/*MAIN_T*/
