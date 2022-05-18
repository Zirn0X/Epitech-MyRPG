/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** player_check_movement
*/

#include <stddef.h>
#include <stdlib.h>
#include "stdio.h"
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void player_moved_in_map_manoir(my_rpg_t *rpg, int **map, int * const new_pos)
{
    map[new_pos[0]][new_pos[1]] = 0;
    map[rpg->player->tuile_y][rpg->player->tuile_x] = 1;
    rpg->player->tuile_y = new_pos[0];
    rpg->player->tuile_x = new_pos[1];
}

static float get_good_value_manoir(int direction, float pos, int flag)
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

static int *does_player_moved_manoir(my_rpg_t *rpg, int csv, int direction)
{
    int *ret = malloc(sizeof(int) * 2);
    int new_pos_tuile_x =
    find_player_pos(rpg->player->sprite->position.x +
    (45), rpg->maps->csv[csv].len_csv_line, 32.0);
    int new_pos_tuile_y =
    find_player_pos(rpg->player->sprite->position.y
    + 67.5, rpg->maps->csv[csv].len_csv, 32.0);

    if (new_pos_tuile_x != rpg->player->tuile_x ||
    new_pos_tuile_y != rpg->player->tuile_y) {
        ret[0] = new_pos_tuile_y;
        ret[1] = new_pos_tuile_x;
        return (ret);
    }
    return (NULL);
}

int is_direction_valid_manoir(my_rpg_t *rpg, int direction)
{
    if (direction == NORTH)
        if (rpg->maps->csv[CSV_MANOIR].colision[rpg->player->tuile_y - 1]
        [rpg->player->tuile_x] == -1 && rpg->player->sprite->position.y <=
        (float)((rpg->player->tuile_y - 2)) * 32 - 32)
            return (ERROR);
    if (direction == SUD) {
        if (rpg->maps->csv[CSV_MANOIR].colision[rpg->player->tuile_y + 1]
        [rpg->player->tuile_x] == -1 && rpg->player->sprite->position.y >=
        (float)((rpg->player->tuile_y - 2)) * 32 - 16)
            return (ERROR);
    }
    if (direction == WEST)
        if (rpg->maps->csv[CSV_MANOIR].colision[rpg->player->tuile_y]
        [rpg->player->tuile_x - 1] == -1 && rpg->player->sprite->position.x <=
        (float)((rpg->player->tuile_x - 3)) * 32 + 32)
            return (ERROR);
    if (direction == EAST) {
        if (rpg->maps->csv[CSV_MANOIR].colision[rpg->player->tuile_y]
        [rpg->player->tuile_x + 1] == -1 && rpg->player->sprite->position.x >=
        (float)((rpg->player->tuile_x - 3)) * 32 + 32) {
            return (ERROR);
        }
    }
    return (SUCCESS);
}

int player_check_movement_manoir(my_rpg_t *rpg, int direction)
{
    int *player_new_pos = NULL;

    if (is_direction_valid_manoir(rpg, direction) == ERROR)
        return (ERROR);
    player_new_pos = does_player_moved_manoir(rpg, CSV_MANOIR, direction);
    if (player_new_pos != NULL) {
        player_moved_in_map_manoir(rpg, rpg->maps->csv[CSV_MANOIR].colision,
        player_new_pos);
        return (NOT_COLISION);
    }
    return (SUCCESS);
}
