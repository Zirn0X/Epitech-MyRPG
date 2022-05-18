/*
** EPITECH PROJECT, 2022
** set_lantern.c
** File description:
** set_lantern
*/

#include "my_rpg.h"
#include "my_lib.h"

int set_lantern(my_rpg_t *rpg)
{
    rpg->all_objects->lantern = create_object("lantern", 1, 100, 1);
    rpg->all_objects->lantern->flag = 'L';
}
