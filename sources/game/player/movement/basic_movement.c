/*
** EPITECH PROJECT, 2022
** basic_movement.c
** File description:
** basic_movement
*/

#include "my_rpg.h"
#include "my_macro.h"

void player_check_movement(my_rpg_t *rpg);

static void key_move(my_rpg_t *rpg, int key, int direction)
{
    if (rpg->manager->input->keys[key]->status == sfTrue) {
        rpg->player->speed[direction] = rpg->player->speed[direction]
        + rpg->player->sprite->action->acceleration * rpg->manager->dt->time;
        if (rpg->player->speed[direction] > rpg->player->sprite->action->
        speed_max)
            rpg->player->speed[direction] = rpg->player->sprite->action->speed_max;
        rpg->player->move(rpg->player->speed[direction], rpg, direction);
    } else {
        rpg->player->speed[direction] = rpg->player->speed[direction]
        - rpg->player->sprite->action->acceleration * rpg->manager->dt->time;
        if (rpg->player->speed[direction] < 0)
            rpg->player->speed[direction] = 0;
        rpg->player->move(rpg->player->speed[direction], rpg, direction);
    }
}

void top_bot(my_rpg_t *rpg)
{
    if ((rpg->manager->input->keys[KEY_NORTH]->status == sfTrue &&
    rpg->manager->input->keys[KEY_SUD]->status == sfTrue)) {
        rpg->player->speed[SUD] = 0;
        rpg->player->speed[NORTH] = 0;
        return;
    }
    key_move(rpg, KEY_NORTH, NORTH);
    key_move(rpg, KEY_SUD, SUD);
}

void left_right(my_rpg_t *rpg)
{
    if ((rpg->manager->input->keys[KEY_WEST]->status == sfTrue &&
    rpg->manager->input->keys[KEY_EAST]->status == sfTrue)) {
        rpg->player->speed[WEST] = 0;
        rpg->player->speed[EAST] = 0;
        return;
    }
    key_move(rpg, KEY_WEST, WEST);
    key_move(rpg, KEY_EAST, EAST);
}
