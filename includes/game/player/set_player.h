/*
** EPITECH PROJECT, 2022
** set_player.h
** File description:
** set_player
*/

#ifndef SET_PLAYER_H_
    #define SET_PLAYER_H_

typedef struct my_rpg_s my_rpg_t;

void player_move(float move_value, my_rpg_t *rpg, int direction);
void set_player_objects(my_rpg_t *rpg);
void set_player_competencies(my_rpg_t *rpg);;
int set_player_actions(my_rpg_t *rpg);

#endif /* !SET_PLAYER_H_ */
