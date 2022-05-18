/*
** EPITECH PROJECT, 2022
** check_colision_player.c
** File description:
** check_colision_player
*/

#include "my_rpg.h"
#include "my_macro.h"

int player_check_movement(my_rpg_t *rpg, int direction);
int player_check_movement_manoir(my_rpg_t *rpg, int direction);

int check_colision_player(my_rpg_t *rpg, int direction)
{
    int colision = 0;

    if (rpg->game->scenes == S_EXTERIORS)
        colision = player_check_movement(rpg, direction);
    else
        colision = player_check_movement_manoir(rpg, direction);
    if (colision == ERROR) {
        rpg->player->speed[direction] = 0;
        return (ERROR);
    }
    return (SUCCESS);
}