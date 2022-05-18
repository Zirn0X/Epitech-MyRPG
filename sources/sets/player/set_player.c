/*
** EPITECH PROJECT, 2022
** preset_player.c
** File description:
** preset_player
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "game/player/set_player.h"
#include "my_lib.h"

void set_bar_life(my_sprite_t *sprite, sfVector2f size, sfVector2f position,
sfColor color);

void set_movement(movement_id_t *move_id)
{
    move_id->north = RELEASED;
    move_id->sud = RELEASED;
    move_id->east = RELEASED;
    move_id->west = RELEASED;
}

static void set_value_player(my_rpg_t *rpg)
{
    rpg->player->speed = malloc(sizeof(float) * 10);
    rpg->player->colision = malloc(sizeof(bool) * 5);
    rpg->player->sprite = malloc(sizeof(my_sprite_t));
    rpg->player->sprite->action = malloc(sizeof(action_t));
    rpg->player->sprite->sprite = sfSprite_create();
    rpg->player->sprite->position.x = 700;
    rpg->player->sprite->position.y = 400;
    rpg->player->size_x = 200;
    rpg->player->size_y = 100;
    rpg->player->move = &(player_move);
    rpg->player->sprite->action->acceleration = 7;
    rpg->player->sprite->action->speed_max = 2;
    rpg->player->sprite->action->speed_max_anim = 0.2;
    rpg->player->sprite->damage = 10;
    rpg->player->sprite->life = 500;
    rpg->player->curr_direction = NO_MOVE;
    for (int i = 0; i != 10; i += 1)
        rpg->player->speed[i] = 0;
    for (int i = 0; i != 5; ++i)
        rpg->player->colision[i] = false;
    return;
}

void set_player_animation(my_rpg_t *rpg)
{
    rpg->player->animations->clock = sfClock_create();
    rpg->player->animations->seconds = 0;
    return;
}

int set_player(my_rpg_t *rpg)
{
    if ((rpg->player = malloc(sizeof(my_player_t))) == NULL)
        return (ERROR);
    if ((rpg->player->move_id = malloc(sizeof(movement_id_t))) == NULL)
        return (ERROR);
    if ((rpg->player->animations = malloc(sizeof(animation_t))) == NULL)
        return (ERROR);
    if ((rpg->player->compentencies = malloc(sizeof(player_competencies_t)
            )) == NULL)
        return (ERROR);
    set_player_objects(rpg);
    set_movement(rpg->player->move_id);
    set_value_player(rpg);
    set_player_animation(rpg);
    set_player_competencies(rpg);
    set_player_actions(rpg);
    set_bar_life(rpg->player->sprite, (sfVector2f) {rpg->player->sprite->life,
    50}, (sfVector2f)
    {rpg->player->sprite->position.x, rpg->player->sprite->position.y -
    990}, sfGreen);
    rpg->player->id = 0;
    rpg->player->sprite->rect = set_rect(PLAYER_WIDTH, 0, 0, PLAYER_HEIGHT);
    set_texture_sprite(&(rpg->player->sprite->sprite), rpg->all_texture->player_txt,
    "assets/player/hero_new.png", rpg->player->sprite->rect);
    sfSprite_setPosition(rpg->player->sprite->sprite, rpg->player->sprite->
    position);
    return (SUCCESS);
}
