/*
** EPITECH PROJECT, 2022
** basic_move.h
** File description:
** basic_move
*/

#ifndef BASIC_MOVE_H_
    #define BASIC_MOVE_H_

typedef struct my_rpg_s my_rpg_t;

void left_right(my_rpg_t *rpg);
void player_sprint(my_rpg_t *rpg);
int player_dash(my_rpg_t *rpg);
void top_bot(my_rpg_t *rpg);

#endif /* !BASIC_MOVE_H_ */
