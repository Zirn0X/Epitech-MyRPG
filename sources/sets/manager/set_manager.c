/*
** EPITECH PROJECT, 2022
** set_manager.c
** File description:
** set_manage
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "manager/my_sets.h"

void set_manager(my_rpg_t *rpg)
{
    set_window(rpg->manager);
    set_cursor(rpg);
    set_camera(rpg);
    set_home_camera(rpg);
    rpg->manager->sound = 0;
    rpg->manager->end = 0;
    set_delta_time(rpg);
    set_keys(rpg);
    rpg->manager->display_zone = 1500.0;
    return;
}