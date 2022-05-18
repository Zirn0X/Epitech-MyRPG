/*
** EPITECH PROJECT, 2022
** set_player_actions.c
** File description:
** set_player_actions
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "game/player/action/player_action.h"

void set_a_action(action_t *action, float *value, void (*function),
bool *bool_action)
{
    action->speed_max = value[0];
    action->acceleration = value[1];
    action->seconds = value[2];
    action->action = function;
    action->activate = bool_action[0];
    action->animated = bool_action[1];
    action->scd_animation = 0;
    action->turn = 0;
}

int set_player_actions(my_rpg_t *rpg)
{
    float attack[] = {0.8, 10.0, 0.0};
    bool attack_b[] = {false, true};
    float run[] = {0.2, 1.0, 0.0};
    bool run_b[] = {false, false};
    float interaction[] = {0.2, 1.0, 0.0};
    bool interaction_b[] = {false, false};
    float skip[] = {0.2, 1.0, 0.0};
    bool skip_b[] = {false, false};
    float leave[] = {0.2, 1.0, 0.0};
    bool leave_b[] = {false, false};
    float leave_ext[] = {0.2, 1.0, 0.0};
    bool leave_ext_b[] = {false, false};

    rpg->player->actions = malloc(sizeof(action_t) * PLAYER_NB_ACTIONS);
    set_a_action(&rpg->player->actions[ACTION_RUN_P], run, &(action_player_run)
    , run_b);
    set_a_action(&rpg->player->actions[ACTION_ATTACK_P], attack,
    &(action_player_attacks), attack_b);
    set_a_action(&rpg->player->actions[ACTION_INTERACTION_P], interaction,
                 &(action_player_interact), interaction_b);
    set_a_action(&rpg->player->actions[ACTION_SKIP_DIALOG_P],
                 skip, &(action_player_skip), skip_b);
    set_a_action(&rpg->player->actions[ACTION_LEAVE_HOUSE_P],
                 leave, &(action_player_house), leave_b);
    set_a_action(&rpg->player->actions[ACTION_LEAVE_EXTERIOR_P], leave_ext, &(action_player_exterior), leave_ext_b);
}