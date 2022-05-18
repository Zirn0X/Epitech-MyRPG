/*
** EPITECH PROJECT, 2022
** activate_spanwer.c
** File description:
** activate_spawner
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void enemy_spawn_at_time(my_rpg_t *rpg, int type_spawn, int scd_spawn_max);
void display_monster(my_rpg_t *rpg, monster_type_t *monster, int nb_monsters);


void activate_spawner(my_rpg_t *rpg, int type_spawner)
{
    monster_type_t *monster = &rpg->monsters->monsters[type_spawner];

    enemy_spawn_at_time(rpg, type_spawner, 15);
    display_monster(rpg, monster, M_FLYING_EYE_NB);
}