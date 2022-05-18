/*
** EPITECH PROJECT, 2022
** set_objects.c
** File description:
** set_objects
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "objects/objects_set.h"

int set_objects(my_rpg_t *rpg)
{
    if (set_lantern(rpg) == ERROR)
        return (ERROR);
    set_health_potion(rpg);
    set_defense_potion(rpg);
    set_attack_potion(rpg);
    set_speed_potion(rpg);
    set_bandage(rpg);
    set_obj_mushroom(rpg);
    set_obj_paper(rpg);
    set_obj_cape(rpg);
    if (set_quest_object(rpg) == ERROR)
        return (ERROR);
    return (SUCCESS);
}