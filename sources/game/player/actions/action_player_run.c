/*
** EPITECH PROJECT, 2022
** action_player_run.c
** File description:
** action_player_run
*/

#include "my_rpg.h"
#include "my_macro.h"

void action_player_run(my_rpg_t *rpg)
{
    if (rpg->manager->input->keys[KEY_SPRINT]->status == sfTrue) {
        rpg->player->sprite->action->speed_max = 4;
        rpg->player->sprite->action->acceleration = 14;
        rpg->player->sprite->action->speed_max_anim = 0.1;
    } else {
        rpg->player->sprite->action->speed_max = 2;
        rpg->player->sprite->action->acceleration = 7;
        rpg->player->sprite->action->speed_max_anim = 0.2;
        rpg->player->actions[ACTION_RUN_P].activate = false;
    }
}