/*
** EPITECH PROJECT, 2022
** player_animation.c
** File description:
** player_animation
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void player_animation(my_rpg_t *rpg)
{
    rpg->player->animations->time = sfClock_getElapsedTime
    (rpg->player->animations->clock);
    rpg->player->animations->seconds =
    rpg->player->animations->time.microseconds / 1000000.0f;
    if (rpg->player->animations->seconds >
    rpg->player->sprite->action->speed_max_anim) {
        if (rpg->manager->input->keys[KEY_WEST]->status == sfTrue)
            move_rect(&(rpg->player->sprite->rect), PLAYER_WIDTH, PLAYER_WIDTH * 5, 0);
        if (rpg->manager->input->keys[KEY_EAST]->status == sfTrue)
            move_rect(&(rpg->player->sprite->rect), PLAYER_WIDTH, PLAYER_WIDTH * 5, 0);
        if (rpg->manager->input->keys[KEY_NORTH]->status == sfTrue)
            move_rect(&(rpg->player->sprite->rect), PLAYER_WIDTH, PLAYER_WIDTH * 5, 0);
        if (rpg->manager->input->keys[KEY_SUD]->status == sfTrue)
            move_rect(&(rpg->player->sprite->rect), PLAYER_WIDTH, PLAYER_WIDTH * 5, 0);
        sfSprite_setTextureRect(rpg->player->sprite->sprite, rpg->player->sprite->rect);
        sfClock_restart(rpg->player->animations->clock);
    }
}