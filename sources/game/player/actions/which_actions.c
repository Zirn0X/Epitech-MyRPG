/*
** EPITECH PROJECT, 2022
** which_action.c
** File description:
** which_actions
*/

#include "my_rpg.h"
#include "my_macro.h"

void player_action_animated(my_rpg_t *rpg, action_t *action, int key,
int turn_max_animation);

void which_actions(my_rpg_t *rpg, int key)
{
    if (rpg->player->actions[key].animated == false)
        rpg->player->actions[key].action(rpg,
        &rpg->player->actions[key], key, 0);
    else
        player_action_animated(rpg, &rpg->player->actions[key], key, 3);
}