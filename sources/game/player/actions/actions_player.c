/*
** EPITECH PROJECT, 2022
** actions_player.c
** File description:
** actions_player
*/

#include "my_rpg.h"
#include "my_macro.h"

void which_actions(my_rpg_t *rpg, int key);

void actions_player(my_rpg_t *rpg)
{
    for (int i = 0; i != PLAYER_NB_ACTIONS; ++i) {
        if (rpg->player->actions[i].activate == true)
            which_actions(rpg, i);
    }
}