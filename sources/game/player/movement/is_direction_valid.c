/*
** EPITECH PROJECT, 2022
** is_direction_valid.c
** File description:
** is_direction_valid
*/

#include "my_rpg.h"
#include "my_macro.h"

static int check_pixels_direction(my_rpg_t *rpg, float y, float x, int direction)
{
    float pos_x = x * (TUILE_SIZE * MULTIPLICATOR_SIZE);
    float pos_y = y * (TUILE_SIZE * MULTIPLICATOR_SIZE);

    if (direction == NORTH)
        if (rpg->player->sprite->position.y + 75 <= pos_y + (TUILE_SIZE * MULTIPLICATOR_SIZE))
            return (ERROR);
    if (direction == SUD)
        if (rpg->player->sprite->position.y + 25 >= pos_y - (TUILE_SIZE * MULTIPLICATOR_SIZE))
            return (ERROR);
    if (direction == WEST)
        if (rpg->player->sprite->position.x - 25 <= pos_x)
            return (ERROR);
    if (direction == EAST)
        if (rpg->player->sprite->position.x + 25 >= pos_x - (TUILE_SIZE * MULTIPLICATOR_SIZE))
            return (ERROR);
    return (SUCCESS);
}

int is_direction_valid(my_rpg_t *rpg, int direction, int csv)
{
    if (direction == NORTH)
        if (rpg->maps->csv[csv].colision[rpg->player->tuile_y - 1][rpg->player->tuile_x] == -1)
            if (check_pixels_direction(rpg,
            (float) rpg->player->tuile_y - 1, (float) rpg->player->tuile_x, NORTH) == ERROR)
                return (ERROR);
    if (direction == SUD)
        if (rpg->maps->csv[csv].colision[rpg->player->tuile_y + 1][rpg->player->tuile_x] == -1)
            if (check_pixels_direction(rpg,
            (float) rpg->player->tuile_y + 1, (float) rpg->player->tuile_x, SUD) == ERROR)
                return (ERROR);
    if (direction == EAST)
        if (rpg->maps->csv[csv].colision[rpg->player->tuile_y][rpg->player->tuile_x + 1] == -1)
            if (check_pixels_direction(rpg,
            (float) rpg->player->tuile_y, (float) rpg->player->tuile_x + 1, EAST) == ERROR)
                return (ERROR);
    if (direction == WEST)
        if (rpg->maps->csv[csv].colision[rpg->player->tuile_y][rpg->player->tuile_x - 1] == -1)
            if (check_pixels_direction(rpg,
            (float) rpg->player->tuile_y, (float) rpg->player->tuile_x - 1, WEST) == ERROR)
                return (ERROR);
    return (SUCCESS);
}
