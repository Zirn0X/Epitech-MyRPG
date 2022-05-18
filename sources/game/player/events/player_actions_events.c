/*
** EPITECH PROJECT, 2022
** player_actions_events.c
** File description:
** player_actions_events
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "manager/my_input.h"

void player_actions_events(my_rpg_t *rpg, sfEventType event, int key,
int action)
{
    if (is_key_correct_type(rpg, key, KEYS_P_FIRST_ACTIONS,
    KEYS_P_FIRST_ACTIONS + KEYS_P_ACTIONS) == SUCCESS) {
        if (event == sfEvtKeyPressed) {
            rpg->manager->input->keys[key]->status = true;
            rpg->player->actions[action].activate = true;
        } else
            rpg->manager->input->keys[key]->status = false;
    }
}
