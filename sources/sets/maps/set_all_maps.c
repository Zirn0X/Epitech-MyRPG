/*
** EPITECH PROJECT, 2022
** set_all_maps.c
** File description:
** set_all_maps
*/

#include <stdlib.h>
#include "map/maps_presets.h"
#include "my_macro.h"
#include "my_rpg.h"

int set_all_maps(my_rpg_t *rpg)
{
    if ((rpg->maps->maps = malloc(sizeof(map_t) * NB_MAPS)) == NULL)
        return (ERROR);
    if (set_manoir(rpg) == ERROR)
        return (ERROR);
    if (set_exteriors(rpg) == ERROR)
        return (ERROR);
    if (set_cave(rpg) == ERROR)
        return (ERROR);
    return (SUCCESS);
}