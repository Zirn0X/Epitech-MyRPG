/*
** EPITECH PROJECT, 2022
** set_pos_random_in_spawner.c
** File description:
** set_pos_random_in_spawner
*/

#include <math.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

sfVector2f set_pos_random_in_spawner(my_rpg_t *rpg, spawner_t *spawner)
{
    int pos_left = ((int)spawner->pos.x - (int)(spawner->range_spawn / 2));
    int pos_width = ((int)spawner->pos.x + (int)(spawner->range_spawn / 2));
    int pos_top = ((int)spawner->pos.y - (int)(spawner->range_spawn / 2));
    int pos_height = ((int)spawner->pos.y + (int)(spawner->range_spawn / 2));
    int *pos_point = malloc(sizeof(int) * 2);

    pos_point[0] = f_get_rand(pos_left, pos_width);
    pos_point[1] = f_get_rand(pos_top, pos_height);
    return ((sfVector2f) {pos_point[0], pos_point[1]});
}