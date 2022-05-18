/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Set Cave
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void set_layer(map_t *map_struct, char *texture,
               char *csv_map, int width, int i);

int set_cave(my_rpg_t *rpg)
{
    if ((rpg->maps->maps[TM_CAVE] = malloc(sizeof(map_t) *
                                             (L_CAVE + 1))) == NULL)
        return (ERROR);
    for (int i = 0; i != CAVE_LAYER; ++i) {
        set_layer(&rpg->maps->maps[TM_CAVE][i], "assets/Fulltilemap.png",
                  rpg->maps->csv[CSV_CAVE].layers[i].name, 640, 1);
    }
    return (SUCCESS);
}

