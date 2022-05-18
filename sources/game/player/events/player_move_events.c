/*
** EPITECH PROJECT, 2022
** player_move_events.c
** File description:
** player_move_events
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "manager/my_input.h"

void get_animation(my_rpg_t *rpg, int key);;

void player_move_events(my_rpg_t *rpg, sfEventType event, int key)
{
    if (is_key_correct_type(rpg, key, 0, KEYS_P_MOVE) == SUCCESS) {
        if (event == sfEvtKeyPressed) {
            rpg->player->curr_direction = key;
            rpg->manager->input->keys[key]->status = sfTrue;
            get_animation(rpg, key);
        }
        if (event == sfEvtKeyReleased) {
            rpg->manager->input->keys[key]->status = sfFalse;
            get_animation(rpg, key);
        }
    }
}