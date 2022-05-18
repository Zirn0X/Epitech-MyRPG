/*
** EPITECH PROJECT, 2022
** set_monsters.c
** File description:
** set_monsters
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "monsters/monsters_sets.h"

int set_monsters(my_rpg_t *rpg)
{
    rpg->monsters->monsters = malloc(sizeof(monster_type_t) * MONSTERS_TYPES_NB);
    if (rpg->monsters->monsters == NULL)
        return (ERROR);
    set_flying_eye(rpg, &rpg->monsters->monsters[M_FLYING_EYE]);
    set_thief(rpg, &rpg->monsters->monsters[M_THIEF]);
    set_skeleton(rpg, &rpg->monsters->monsters[M_SKELETON]);
    set_cyclope(rpg, &rpg->monsters->monsters[M_CYCLOPE]);
    return (SUCCESS);
}