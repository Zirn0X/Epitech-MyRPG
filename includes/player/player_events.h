/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** player_events
*/

#ifndef PLAYER_EVENTS_H_
    #define PLAYER_EVENTS_H_
    #include <SFML/Graphics.h>

typedef struct my_rpg_s my_rpg_t;

void player_move_events(my_rpg_t *rpg, sfEventType event, int key);
void player_inventory_events(my_rpg_t *rpg, sfEventType event, int key);
void player_inventory_competencies(my_rpg_t *rpg, sfEventType event, int key);
void player_pause(my_rpg_t *rpg, sfEventType event, int key);
void movement_player(my_rpg_t *rpg);
void actions_player(my_rpg_t *rpg);
void set_rectangle_pos(my_rpg_t *rpg, int add_x, int add_y, int idx);
void draw_inventory_bar(my_rpg_t *rpg);

#endif /* !PLAYER_EVENTS_H_ */
