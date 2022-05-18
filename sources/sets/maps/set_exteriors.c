/*
** EPITECH PROJECT, 2022
** set_exteriors.c
** File description:
** set_exteriors
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void set_layer(map_t *map_struct, char *texture,
               char *csv_map, int width, int i);

int set_exteriors(my_rpg_t *rpg)
{
    if ((rpg->maps->maps[TM_EXTERIORS] = malloc(sizeof(map_t) *
    (EXTERIORS_LAYER + 1))) == NULL)
        return (ERROR);
    for (int i = 0; i != EXTERIORS_LAYER; ++i) {
        set_layer(&rpg->maps->maps[TM_EXTERIORS][i], "assets/Fulltilemap.png",
        rpg->maps->csv[CSV_EXTERIORS].layers[i].name, 640, 1);
    }
    return (SUCCESS);
}
