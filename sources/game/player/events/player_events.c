/*
** EPITECH PROJECT, 2022
** player_events.c
** File description:
** player_events
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "player/player_events.h"

void movement_player(my_rpg_t *rpg);
void actions_player(my_rpg_t *rpg);
void check_player_in_spawner(my_rpg_t *rpg);

static void which_direction_player_is(my_rpg_t *rpg)
{
    if (rpg->manager->input->keys[KEY_WEST]->status == true)
        rpg->player->curr_direction = KEY_WEST;
    if (rpg->manager->input->keys[KEY_EAST]->status == true)
        rpg->player->curr_direction = KEY_EAST;
    if (rpg->manager->input->keys[KEY_WEST]->status == true
    && rpg->manager->input->keys[KEY_EAST]->status == true)
        rpg->player->curr_direction = KEY_SUD;
    if (rpg->manager->input->keys[KEY_NORTH]->status == true)
        rpg->player->curr_direction = KEY_NORTH;
    if (rpg->manager->input->keys[KEY_SUD]->status == true)
        rpg->player->curr_direction = KEY_SUD;
}

void player_events(my_rpg_t *rpg)
{
    which_direction_player_is(rpg);
    movement_player(rpg);
    actions_player(rpg);
    check_player_in_spawner(rpg);
    draw_inventory_bar(rpg);
}