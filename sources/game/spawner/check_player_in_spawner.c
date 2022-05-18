/*
** EPITECH PROJECT, 2022
** check_player_in_spawner.c
** File description:
** check_player_in_spawner
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void activate_spawner(my_rpg_t *rpg, int type_spawner);
int is_enemy_on_spawn(my_rpg_t *rpg, my_sprite_t *sprite, spawner_t *spawner,
int width_max);
void desactive_spawner(my_rpg_t *rpg, int type_monsters, int type_spawn);

static void check_a_spawner(my_rpg_t *rpg, float *pos, int type_monster,
int type_spawn)
{
    if (is_point_in_circle(pos, rpg->monsters->spawner[type_spawn].pos.y,
    rpg->monsters->spawner[type_spawn].pos.x,
    rpg->monsters->spawner[type_spawn].range_spawn))
        activate_spawner(rpg, type_spawn);
    else {
        desactive_spawner(rpg, type_monster, type_spawn);
    }
}

void check_player_in_spawner(my_rpg_t *rpg)
{
    float pos[] = {rpg->player->sprite->position.x, rpg->player->
    sprite->position.y};

    check_a_spawner(rpg, pos, M_FLYING_EYE, SP_FLYING_EYE);
    check_a_spawner(rpg, pos, M_THIEF, SP_THIEF);
    check_a_spawner(rpg, pos, M_SKELETON, SP_SKELETON);
    check_a_spawner(rpg, pos, M_CYCLOPE, SP_CYCLOPE);
}