/*
** EPITECH PROJECT, 2022
** actualise_map.c
** File description:
** actualise_map.c
*/

#include "my_rpg.h"

void actualise_map(my_rpg_t *rpg, int map, int layer, int csv)
{
    rpg->maps->map_use = map;
    rpg->maps->layer_map = layer;
    rpg->maps->csv_use = csv;
}