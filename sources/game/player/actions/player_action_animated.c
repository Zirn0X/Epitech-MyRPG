/*
** EPITECH PROJECT, 2022
** player_execture_action.c
** File description:
** player_execute_action
*/

#include "my_rpg.h"
#include "my_macro.h"

void player_action_animated(my_rpg_t *rpg, action_t *action, int key,
int turn_max_animation)
{
    if (action->activate == true && action->turn <= turn_max_animation) {
        action->seconds = action->seconds + action->acceleration *
        rpg->manager->dt->time;
        if (action->seconds >= action->speed_max) {
            action->action(rpg, action, key, turn_max_animation);
            action->seconds = 0;
        }
    } else {
        action->activate = false;
        action->turn = 0;
    }
}
