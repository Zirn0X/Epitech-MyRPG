/*
** EPITECH PROJECT, 2022
** player_move.c
** File description:
** player_move
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "game/player/basic_move.h"

void player_animation(my_rpg_t *rpg);
void player_check_movement(my_rpg_t *rpg);
int check_colision_player(my_rpg_t *rpg, int direction);

void player_move(float move_value, my_rpg_t *rpg, int direction)
{
    if (rpg->scenes->sub_scenes != S_MANOIR)
        return;
    if (check_colision_player(rpg, direction) == ERROR)
        return;
    switch (direction) {
    case NORTH:
        rpg->player->sprite->position.y -= move_value;
        break;
    case SUD:
        rpg->player->sprite->position.y += move_value;
        break;
    case WEST:
        rpg->player->sprite->position.x -= move_value;
        break;
    case EAST:
        rpg->player->sprite->position.x += move_value;
        break;
    }
    sfSprite_setPosition(rpg->player->sprite->sprite,
    rpg->player->sprite->position);
    return;
}

void movement_player(my_rpg_t *rpg)
{
    left_right(rpg);
    top_bot(rpg);
    player_animation(rpg);
}
