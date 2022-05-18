/*
** EPITECH PROJECT, 2022
** player_action.h
** File description:
** player_action
*/

#ifndef PLAYER_ACTION_H_
    #define PLAYER_ACTION_H_

typedef struct my_rpg_s my_rpg_t;

void action_player_run(my_rpg_t *rpg);
void action_player_attacks(my_rpg_t *rpg);
void action_player_interact(my_rpg_t *rpg);
void action_player_skip(my_rpg_t *rpg);
void action_player_house(my_rpg_t *rpg);
void action_player_exterior(my_rpg_t *rpg);

#endif /* !PLAYER_ACTION_H_ */
