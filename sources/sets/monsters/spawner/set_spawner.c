/*
** EPITECH PROJECT, 2022
** set_spawner.c
** File description:
** set_spawner
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"

void search_spawner(my_rpg_t *rpg, int type_spawner, int csv_spawner);

static void set_a_spawner(my_rpg_t *rpg, int monster_type, int csv_spawner,
float range)
{
    search_spawner(rpg, monster_type, csv_spawner);
    rpg->monsters->spawner[monster_type].activate = false;
    rpg->monsters->spawner[monster_type].range_spawn = range;
}

int set_spawners(my_rpg_t *rpg)
{
    rpg->monsters->spawner = malloc(sizeof(spawner_t) * SPAWNERS_NB);
    set_a_spawner(rpg, SP_FLYING_EYE, SP_CSV_FLYING_EYE, 1000);
    set_a_spawner(rpg, SP_THIEF, SP_CSV_THIEF, 1000);
    set_a_spawner(rpg, SP_SKELETON, SP_CSV_SKELETON, 750);
    set_a_spawner(rpg, SP_CYCLOPE, SP_CSV_CYCLOPE, 2250);
}