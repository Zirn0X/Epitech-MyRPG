/*
** EPITECH PROJECT, 2022
** my_rpg.h
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
    #define MY_RPG_H_
    #include <SFML/Window/Mouse.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>

typedef struct my_rpg_s my_rpg_t;
typedef struct action_s action_t;

typedef struct button_s {
    sfRectangleShape *button;
    sfIntRect rect;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f hit_min;
    sfVector2f hit_max;
} button_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    char *string;
    sfVector2f pos;
    int changable;
} text_t;

typedef struct interface_s {
    button_t **button;
    text_t *name;
    sfSprite *sprite_back;
    sfTexture *texture_back;
    sfSprite *sprite_cursor;
    sfTexture *texture_cursor;
    sfVector2f pos_mouse;
    sfMusic *music;
    int nb_rect;
    int selected;
    int id;
} interface_t;

typedef struct delta_time_s {
    sfClock *clock;
    sfTime curr;
    sfTime last;
    float time;
} delta_time_t;

typedef struct my_key_s {
    sfKeyCode key;
    int status;
    void (*action) (my_rpg_t *rpg);
} my_key_t;

typedef struct input_s {
    my_key_t **keys;
    sfKeyCode key_input;
} input_t;

typedef struct manager_s {
    delta_time_t *dt;
    input_t *input;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    sfView *camera;
    sfView *view_home;
    int sound;
    int end;
    float display_zone;
} manager_t;

typedef struct my_sprite_s {
    action_t *action;
    sfRectangleShape *bar_life;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f spawner;
    sfIntRect rect;
    bool activate;
    int offset;
    int off_set_max;
    float life;
    float damage;
    float scd_attack;
    float sdc_attack_max;
    float speed_sdc_attack;
} my_sprite_t;

typedef struct my_text_s {
    sfText *text;
    sfVector2f position;
    sfFont *font;
} my_text_t;

typedef struct movement_id_s {
    int north;
    int sud;
    int west;
    int east;
} movement_id_t;

typedef struct animation_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} animation_t;

typedef struct objects_s {
    char *name;
    sfRectangleShape *rect;
    sfTexture *texture;
    sfVector2f pos;
    int quantity;
    int durability;
    int damage;
    char flag;
} objects_t;

typedef struct my_rectshape_s {
    sfRectangleShape *rect_shape;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f hit_min;
    sfVector2f hit_max;
    char flag;
    objects_t *obj;
} my_rectshape_t;

typedef struct player_objects_s {
    objects_t object;
    char flag;
    bool owned;
    bool used;
} player_objects_t;

typedef struct competencies_interface_s {
    my_sprite_t *s_competencies;
    my_text_t *t_competencies;
    button_t *b_competencies;
} competencies_interface_t;

typedef struct player_competencies_s {
    int points;
    int life;
    int attack;
    int resistance;
    int speed;
    int id;
} player_competencies_t;

typedef struct player_inventory_s {
    my_sprite_t *sprite;
    my_rectshape_t *rectangle;
} player_inventory_t;

typedef struct action_s {
    char *name;
    float scd_spawn;
    float scd_spawn_max;
    float speed_max;
    float speed_max_anim;
    float acceleration;
    float seconds;
    float scd_animation;
    void (*action) (my_rpg_t *rpg, action_t *action, int key, int max_anim);
    bool activate;
    bool animated;
    int turn;
} action_t;

typedef struct my_player_s {
    animation_t *animations;
    player_objects_t *objects;
    action_t *actions;
    my_sprite_t *sprite;
    sfIntRect rect_save;
    movement_id_t *move_id;
    int life;
    player_competencies_t *compentencies;
    player_inventory_t *inventory;
    int curr_direction;
    void (*move)(float move_value, my_rpg_t *rpg, int direction);
    float *speed;
    bool *colision;
    int size_x;
    int size_y;
    int tuile_x;
    int tuile_y;
    int id;
    char *name;
} my_player_t;

typedef struct game_s {
    my_rectshape_t *zone_h_leave;
    my_rectshape_t *zone_ext_leave;
    int scenes;
    int quests;
    int is_in_dialog;
    int current_dialog;
} game_t;

typedef struct scenes_s {
    int (***scenes) (my_rpg_t *rpg);
    void (***events) (my_rpg_t *rpg);
    int type_scenes;
    int sub_scenes;
} scenes_t;

typedef struct map_s {
    char **char_map_array;
    int **int_map_array;
    float **x;
    float **y;
    sfSprite ***map_sprite;
    int width;
    int lines;
    int cols;
    char *sprite_texture;
    char *csv_map;
} map_t;

typedef struct csv_layer_name_s {
    char *name;
    bool colisionable;
} csv_layer_name_t;

typedef struct csv_s {
    csv_layer_name_t *layers;
    int **colision;
    int *colision_id;
    int len_csv;
    int len_csv_line;
} csv_t;

typedef struct maps_s {
    map_t **maps;
    csv_t *csv;
    int map_use;
    int layer_map;
    int csv_use;
} maps_t;

typedef struct textures_s {
    sfTexture *player_txt;
} textures_t;

typedef struct effect_s {
    my_sprite_t *shadow;
    my_sprite_t *lanthern;
    int darkest;
} effect_t;

typedef struct quest_object_s {
    int nb_mushroom_get;
    int nb_paper_get;
    int nb_cape_get;
    objects_t *mushroom;
    objects_t *paper;
    objects_t *cape;
} quest_object_t;

typedef struct all_objects_s {
    objects_t *lantern;
    objects_t *health_potion;
    objects_t *defense_potion;
    objects_t *attack_potion;
    objects_t *speed_potion;
    objects_t *bandage;
    objects_t *mushroom;
    objects_t *paper;
    objects_t *cape;
    quest_object_t *quest_obj;
} all_objects_t;

typedef struct spawner_s {
    sfVector2f pos;
    bool activate;
    float range_spawn;
} spawner_t;

typedef struct monster_type_s {
    my_sprite_t *monster;
    int nb_monster;
    float scd_spawn;
    float scd_spawn_max;
    int sp_acce;
    int damage;
    int life;
} monster_type_t;

typedef struct monster_s {
    monster_type_t *monsters;
    spawner_t *spawner;
} monster_t;

typedef struct npc_s {
    my_rectshape_t *rect_npc;
} npc_t;

typedef struct chatbox_s {
    char const *pathfile;
    char *buffer;
    char *text_cut;
    sfRectangleShape *box;
    sfSprite *s_box;
    sfTexture *s_texure;
    sfText *text;
    sfFont *font;
    sfTime time;
    sfClock *clock;
    float seconds;
    int pos;
    sfVector2f pos_box;
} chatbox_t;

typedef struct quest_s {
    my_sprite_t *sprite;
    my_text_t *text;
    char *content_file;
} quest_t;

typedef struct my_rpg_s {
    scenes_t *scenes;
    interface_t *home_menu;
    interface_t *home_setting;
    interface_t *home_save;
    interface_t *pause;
    manager_t *manager;
    game_t *game;
    my_player_t *player;
    int fps;
    int current_type;
    int current_sub;
    maps_t *maps;
    textures_t *all_texture;
    effect_t *effects;
    all_objects_t *all_objects;
    competencies_interface_t *menu_competencies;
    monster_t *monsters;
    npc_t *npcs;
    chatbox_t *chatbox;
    quest_t *quests;
} my_rpg_t;

#endif /* !MY_RPG_H_ */
