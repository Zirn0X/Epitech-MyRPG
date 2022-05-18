/*
** EPITECH PROJECT, 2022
** my_macro.H
** File description:
** my_macro
*/

#ifndef MY_MACRO_H_
    #define MY_MACRO_H_

// Return value
static const int ERROR = -1;
static const int SUCCESS = 1;
static const int ERROR_RETURN = 84;
// Number total
static const int NB_TYPE_SCENES = 2;
static const int NB_GAME_SCENES = 5;
static const int NB_MENU_SCENES = 3;
// MAPS
static const float TUILE_SIZE = 32.0;
static const float MULTIPLICATOR_SIZE = 2.5;
// COlISION
static const int COLISION = 2;
static const int NOT_COLISION = 3;
// SAVE PAGE
    // PLAYER SELECTED
enum player_selected {
    NO_ONE,
    FIRST,
    SECOND,
    THIRD,
};
    // STATES
static const int GO_HOME = 6;
static const int START_GAME = 7;
// PAUSE
    // OPTIONS
enum pause {
    QUIT_OPT,
    RESUME_OPT,
    HOME_OPT,
};
    // STATE
static const int QUIT = -1;
// Keys
static const int KEYS_P_MOVE = 4;
static const int KEYS_P_FIRST_ACTIONS = 4;
static const int KEYS_P_ACTIONS = 6;
static const int KEYS_NB_PLAYER = KEYS_P_MOVE + KEYS_P_ACTIONS;
static const int NB_INVENTORY = 7;
static const int KEY_DIFF_THAN_INV = 3;
static const int NB_KEYS = KEYS_NB_PLAYER + NB_INVENTORY + 4;
static const int NB_MAPS = 3;
// ENUM FRAMERATE
enum framerate {
    FRAME30,
    FRAME60,
    FRAME120,
};

// ENUM MUSIC
enum music {
    UNMUTE,
    MUTE,
};

enum name {
    CHANGABLE,
    NOT_CHANGABLE,
};
    // ENUM
enum keys_p_movement {
    KEY_NORTH,
    KEY_SUD,
    KEY_WEST,
    KEY_EAST,
};

enum keys_p_actions {
    KEY_SPRINT = 4,
    KEY_ATTACK,
    KEY_INTERACT = 6,
    KEY_SKIP_DIALOG = 7,
    KEY_LEAVE_HOUSE = 8,
    KEY_LEAVE_EXETERIOR = 9,
};

enum keys_p_inventory {
    KEY_INVENTORY_1 = 10,
    KEY_INVENTORY_2,
    KEY_INVENTORY_3,
    KEY_INVENTORY_4,
    KEY_INVENTORY_5,
    KEY_INVENTORY_6,
    KEY_INVENTORY_7,
    KEY_COMPETENCIES,
    KEY_ESCAPE,
    KEY_SPACE,
};
// Shadow effect
static const float LEN_SHADOW_X = 500.0 * 4.5;
static const float LEN_SHADOW_Y = 500.0 * 4.0;
// Lanthern effect
static const float LEN_LANTHERN_X = 500.0 * 4.5;
static const float LEN_LANTHERN_Y = 500.0 * 4.0;
// Player
    // Sprite
static const int PLAYER_WIDTH = 67;
static const int PLAYER_WIDTH_SUD = PLAYER_WIDTH + 3;
static const int PLAYER_HEIGHT = 52;
static const int PLAYER_ATTACK_WIDTH_MAX = PLAYER_WIDTH * 5;
static const int PLAYER_ATTACK_WIDTH_MAX_SUD = PLAYER_ATTACK_WIDTH_MAX + 3;
    // Objects
static const int NB_PLAYER_OBJECTS = 7;
static const int NB_INVENTORY_GUI = 1;
    // ACTIONS
static const int PLAYER_NB_ACTIONS = 6;
enum actions_type {
    ACTION_RUN_P,
    ACTION_ATTACK_P,
    ACTION_INTERACTION_P,
    ACTION_SKIP_DIALOG_P,
    ACTION_LEAVE_HOUSE_P,
    ACTION_LEAVE_EXTERIOR_P,
};
// MONSTERS
static const int MONSTERS_TYPES_NB = 4;
    // Types
enum monsters_types {
    M_FLYING_EYE,
    M_THIEF,
    M_CYCLOPE,
    M_SKELETON,
};
    // FLYING EYE
static const int M_FLYING_EYE_NB = 30;
static const int M_FLYING_EYE_WIDTH = 150;
static const int M_FLYING_EYE_HEIGHT = 150;
    // THIEF
static const int M_THIEF_NB = 30;
    // SKELETON
static const int M_SKELETON_NB = 30;
    // CYCLOPE
static const int M_CYCLOPE_NB = 90;
    // SPAWNERS
static const int SPAWNERS_NB = 4;
static const int SP_CSV_FLYING_EYE = 175;
static const int SP_CSV_THIEF = 174;
static const int SP_CSV_SKELETON = 195;
static const int SP_CSV_CYCLOPE = 194;
enum spawners_types {
    SP_FLYING_EYE,
    SP_THIEF,
    SP_CYCLOPE,
    SP_SKELETON,
};

static const int NPCS_NB = 1;
static const int NB_MUSHROOM = 10;
static const int NB_PAPER = 3;
static const int NB_CAPE = 5;

// CSV
static const int NB_SCENES_CSV = 3;
    // MANOIR
static const int MANOIR_LAYERS = 4;
static const int MANOIR_NB_ID_COLISION = 6;
static const int MANOIR_LEN_CSV = 100;
static const int MANOIR_LEN_CSV_LINE = 149;
    // EXTERIORS
static const int EXTERIORS_LAYER = 3;
static const int EXTERIORS_LEN_CSV = 85;
static const int EXTERIORS_LEN_CSV_LINE = 170;

// CAVE
static const int CAVE_LAYER = 2;
static const int CAVE_LEN_CSV = 16;
static const int CAVE_LEN_CSV_LINE = 11;
    // ENUM
enum csv_type {
    CSV_MANOIR,
    CSV_EXTERIORS,
    CSV_CAVE,
};
// ENUM
    // OTHERS
enum movements {
    NO_MOVE,
    NORTH,
    SUD,
    EAST,
    WEST,
};
enum type_scenes {
    TYPE_MENU,
    TYPE_GAME,
};
enum menu_scenes {
    HOME_PAGE,
    SETTING_PAGE,
    SAVE_PAGE,
};
enum game_scenes {
    S_MANOIR,
    S_EXTERIORS = 1,
    S_CAVE,
    S_COMPETENCIES,
    S_PAUSE,
    S_GARDEN,
};
// To add map, just add the name of the map in "types_maps" with his correspond
// game scenes in order. Ex: Room, Manoir
enum types_maps {
    TM_MANOIR,
    TM_EXTERIORS,
    TM_CAVE,
};
enum layers_maps {
    L_MANOIR = 3,
    L_GARDER = 4,
    L_CAVE = 5,
};
enum key_status {
    PRESSED,
    RELEASED,
};

// QUESTS

static const int NB_QUESTS = 9;

enum quests {
    QUEST_1, // FIND
    QUEST_2, // Go talk voisin
    QUEST_3, // Prendre 10 mush
    QUEST_4, // Ramenez
    QUEST_5, // Cherche 3 feuilles
    QUEST_6, // Ramenez
    QUEST_7, // Cimetiere
    QUEST_8, // Ramenez
    QUEST_9, // Aller grotte
};

// CHATBOX
static const int NB_CHATBOX = 4;

enum chat_box {
    CHATBOX_1, // Find Mush
    CHATBOX_2, // Find paper
    CHATBOX_3, // Go cimetiere
    CHATBOX_4, // Go grotte
};

#endif /* !MY_MACRO_H_ */
