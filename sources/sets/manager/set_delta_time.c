/*
** EPITECH PROJECT, 2022
** set_delta_time.c
** File description:
** set_delta_time
*/

#include "my_rpg.h"
#include <stdlib.h>

void set_delta_time(my_rpg_t *rpg)
{
    rpg->manager->dt = malloc(sizeof(delta_time_t));
    rpg->manager->dt->clock = sfClock_create();
    rpg->manager->dt->last.microseconds = 0;
}