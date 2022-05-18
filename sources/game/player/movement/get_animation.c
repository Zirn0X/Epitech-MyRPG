/*
** EPITECH PROJECT, 2022
** get_animation.c
** File description:
** get_animation
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void get_animation(my_rpg_t *rpg, int key)
{
    if (rpg->manager->input->keys[KEY_WEST]->status == sfTrue)
        rpg->player->sprite->rect = set_rect(PLAYER_WIDTH, 0, PLAYER_HEIGHT * 2,
        PLAYER_HEIGHT);
    if (rpg->manager->input->keys[KEY_EAST]->status == sfTrue)
        rpg->player->sprite->rect = set_rect(PLAYER_WIDTH, 0, PLAYER_HEIGHT * 3,
        PLAYER_HEIGHT);
    if (rpg->manager->input->keys[KEY_NORTH]->status == sfTrue)
        rpg->player->sprite->rect = set_rect(PLAYER_WIDTH, 0, 0, PLAYER_HEIGHT);
    if (rpg->manager->input->keys[KEY_SUD]->status == sfTrue)
        rpg->player->sprite->rect = set_rect(PLAYER_WIDTH, 0, PLAYER_HEIGHT * 1,
        PLAYER_HEIGHT);
}