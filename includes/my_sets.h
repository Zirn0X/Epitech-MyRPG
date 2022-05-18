/*
** EPITECH PROJECT, 2022
** my_sets.h
** File description:
** my_sets
*/

#ifndef MY_SETS_H_
    #define MY_SETS_H_

typedef struct my_rpg_s my_rpg_t;
typedef struct manager_s manager_t;
typedef struct input_s input_t;

void set_manager(my_rpg_t *rpg);
int set_all_scenes(my_rpg_t *rpg);
int set_menu(my_rpg_t *rpg);
int set_player(my_rpg_t *rpg);
int set_game(my_rpg_t *rpg);
int set_camera(my_rpg_t *rpg);
void set_cursor(sfRenderWindow *window, interface_t *home);
void set_keys(input_t *input);
int set_all_maps(my_rpg_t *rpg);
int set_effects(my_rpg_t *rpg);
int set_objects(my_rpg_t *rpg);
int set_csv(my_rpg_t *rpg);
int set_spawners(my_rpg_t *rpg);
int set_competencies(my_rpg_t *rpg);
int set_inventory(my_rpg_t *rpg);
int set_pause(my_rpg_t *rpg);
int set_monsters(my_rpg_t *rpg);
int set_npcs(my_rpg_t *rpg);
int set_quests(my_rpg_t *rpg);

#endif /* !MY_SETS_H_ */
