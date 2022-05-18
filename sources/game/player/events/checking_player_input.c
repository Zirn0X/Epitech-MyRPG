/*
** EPITECH PROJECT, 2022
** checking_events.c
** File description:
** checking_events
*/

#include "my_rpg.h"
#include "my_macro.h"

void player_move_events(my_rpg_t *rpg, sfEventType event, int key);
void player_inventory_events(my_rpg_t *rpg, sfEventType event, int key);
void player_actions_events(my_rpg_t *rpg, sfEventType event, int key,
int action);
void player_inventory_competencies(my_rpg_t *rpg, sfEventType event, int key);
void player_pause(my_rpg_t *rpg, sfEventType event, int key);

void check_player_events_pressed(my_rpg_t *rpg, sfKeyCode key_input)
{
    for (int i = 0, action = 0; i != NB_KEYS; ++i) {
        if (i > KEYS_P_FIRST_ACTIONS)
            action++;
        if (rpg->manager->input->keys[i]->key == key_input &&
        rpg->manager->input->keys[i]->status == sfFalse) {
            player_move_events(rpg, sfEvtKeyPressed, i);
            player_inventory_events(rpg, sfEvtKeyPressed, i);
            player_actions_events(rpg, sfEvtKeyPressed, i, action);
            player_inventory_competencies(rpg, sfEvtKeyPressed, i);
            player_pause(rpg, sfEvtKeyPressed, i);
        }
    }
}

void check_player_events_released(my_rpg_t *rpg, sfKeyCode key_input)
{
    for (int i = 0, action = 0; i != NB_KEYS; ++i) {
        if (i > KEYS_P_FIRST_ACTIONS)
            action++;
        if (rpg->manager->input->keys[i]->key == key_input) {
            player_move_events(rpg, sfEvtKeyReleased, i);
            player_actions_events(rpg, sfEvtKeyReleased, i, action);
        }
    }
}
