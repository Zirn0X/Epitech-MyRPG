/*
** EPITECH PROJECT, 2022
** action_player_attacks.c
** File description:
** action_player_attacks
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void get_animation(my_rpg_t *rpg, int key);
void attack_enemies(my_rpg_t *rpg);

void set_attack_sprite(my_rpg_t *rpg, int key, int debut)
{
    if (key == KEY_NORTH)
        rpg->player->sprite->rect = set_rect(PLAYER_WIDTH, debut, PLAYER_HEIGHT * 4,
        PLAYER_HEIGHT);
    if (key == KEY_SUD)
        rpg->player->sprite->rect = set_rect(PLAYER_WIDTH_SUD, debut,
                                     PLAYER_HEIGHT * 5,
        PLAYER_HEIGHT);
    if (key == KEY_WEST) {
        rpg->player->sprite->rect = set_rect(PLAYER_WIDTH, debut, PLAYER_HEIGHT * 6,
        PLAYER_HEIGHT);
    }
    if (key == KEY_EAST) {
        rpg->player->sprite->rect = set_rect(PLAYER_WIDTH, debut, PLAYER_HEIGHT * 7,
        PLAYER_HEIGHT);
    }
}

static void check_last_movement(my_rpg_t *rpg, action_t *action, int turn_max)
{
    if (action->turn == turn_max)
        get_animation(rpg, rpg->player->curr_direction);
}

void action_player_attacks(my_rpg_t *rpg, action_t *action, int key,
int max_anim)
{
    if (action->turn == 0) {
        set_attack_sprite(rpg, rpg->player->curr_direction, 0);
        sfSprite_setTextureRect(rpg->player->sprite->sprite, rpg->player->sprite->rect);
        action->turn++;
        rpg->player->rect_save = rpg->player->sprite->rect;
        attack_enemies(rpg);
        return;
    }
    rpg->player->sprite->rect = rpg->player->rect_save;
    move_rect(&rpg->player->sprite->rect, PLAYER_WIDTH,
    PLAYER_ATTACK_WIDTH_MAX, 0);
    check_last_movement(rpg, action, max_anim);
    sfSprite_setTextureRect(rpg->player->sprite->sprite, rpg->player->sprite->rect);
    action->turn += 1;
    rpg->player->rect_save = rpg->player->sprite->rect;
}
