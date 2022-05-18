/*
** EPITECH PROJECT, 2022
** player_check_input.h
** File description:
** player_check_input
*/

#ifndef PLAYER_CHECK_INPUT_H_
    #define PLAYER_CHECK_INPUT_H_
    #include <SFML/Graphics.h>

typedef struct my_rpg_s my_rpg_t;

void check_player_events_pressed(my_rpg_t *rpg, sfKeyCode key_input);
void check_player_events_released(my_rpg_t *rpg, sfKeyCode key_input);

#endif /* !PLAYER_CHECK_INPUT_H_ */
