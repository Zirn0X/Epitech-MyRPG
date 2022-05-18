/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_bandage
*/

#include "my_rpg.h"
#include "my_lib.h"

#include "my_rpg.h"
#include "my_lib.h"

void set_obj_cape(my_rpg_t *rpg) {
    rpg->all_objects->cape =
            create_object("cape", 1, 100, 1);
    rpg->all_objects->cape->flag = 'C';
}

void set_obj_paper(my_rpg_t *rpg) {
    rpg->all_objects->paper =
            create_object("paper", 1, 100, 1);
    rpg->all_objects->paper->flag = 'P';
}

void set_obj_mushroom(my_rpg_t *rpg) {
    rpg->all_objects->mushroom =
            create_object("mushroom", 1, 100, 1);
    rpg->all_objects->mushroom->flag = 'M';
}


void set_bandage(my_rpg_t *rpg) {
    rpg->all_objects->bandage =
            create_object("bandage", 1, 100, 1);
    rpg->all_objects->bandage->flag = 'B';
}
