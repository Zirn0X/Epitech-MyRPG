/*
** EPITECH PROJECT, 2022
** set_scenes.c
** File description:
** set_scenes
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "game/game_scenes.h"

int set_scenes_game(int (***function)(my_rpg_t *rpg))
{
    if ((function[0] = malloc(sizeof(int *) * NB_GAME_SCENES)) == NULL)
        return (ERROR);
    function[0][0] = &(scenes_game);
    function[0][1] = &(exterior_scene);
    return (SUCCESS);
}