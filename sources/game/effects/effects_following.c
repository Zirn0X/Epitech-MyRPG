/*
** EPITECH PROJECT, 2022
** effects_following.c
** File description:
** effect_following
*/

#include "my_rpg.h"
#include "my_macro.h"

void effects_following(my_rpg_t *rpg, my_sprite_t *effect, float len_x,
float len_y)
{
    effect->position.x = rpg->player->sprite->position.x -
    ((len_x / 2) - (PLAYER_WIDTH / 2)) + 15;
    effect->position.y = rpg->player->sprite->position.y -
    ((len_y / 2) - (PLAYER_WIDTH / 2)) + 15;
    sfSprite_setPosition(effect->sprite,
    effect->position);
}