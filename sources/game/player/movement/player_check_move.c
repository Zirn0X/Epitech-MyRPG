/*
** EPITECH PROJECT, 2022
** player_moved.c
** File description:
** player_moved
*/

#include <stddef.h>
#include <stdlib.h>
#include "stdio.h"
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

int is_direction_valid(my_rpg_t *rpg, int direction, int csv);

void player_moved_in_map(my_rpg_t *rpg, int **map, int * const new_pos)
{
    map[new_pos[0]][new_pos[1]] = 0;
    map[rpg->player->tuile_y][rpg->player->tuile_x] = 1;
    rpg->player->tuile_y = new_pos[0];
    rpg->player->tuile_x = new_pos[1];
}

static float get_good_value(int direction, float pos, int flag)
{
    if (flag == 0) {
        if (direction == NORTH)
            return (pos);
        if (direction == SUD)
            return (pos + PLAYER_HEIGHT);
    }
    if (flag == 1) {
        if (direction == WEST)
            return (pos);
        if (direction == EAST)
            return (pos + PLAYER_WIDTH);
    }
}

static int *does_player_moved(my_rpg_t *rpg, int csv, int direction)
{
    int *ret = malloc(sizeof(int) * 2);
    int new_pos_tuile_x = find_player_pos(rpg->player->sprite->position.x, rpg->maps->csv[csv].
    len_csv_line, TUILE_SIZE * MULTIPLICATOR_SIZE);
    int new_pos_tuile_y = find_player_pos(rpg->player->sprite->position.y, rpg->maps->csv[csv].
    len_csv, TUILE_SIZE * MULTIPLICATOR_SIZE);

    if (new_pos_tuile_x != rpg->player->tuile_x ||
    new_pos_tuile_y != rpg->player->tuile_y) {
        ret[0] = new_pos_tuile_y;
        ret[1] = new_pos_tuile_x;
        return (ret);
    }
    return (NULL);
}

int player_check_movement(my_rpg_t *rpg, int direction)
{
    int *player_new_pos = NULL;

    if (is_direction_valid(rpg, direction, rpg->maps->csv_use) == ERROR)
        return (ERROR);
    player_new_pos = does_player_moved(rpg, rpg->maps->csv_use, direction);
    if (player_new_pos != NULL) {
        player_moved_in_map(rpg, rpg->maps->csv[rpg->maps->csv_use].colision,
        player_new_pos);
        return (NOT_COLISION);
    }
    return (SUCCESS);
}