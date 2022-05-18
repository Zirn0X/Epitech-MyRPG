/*
** EPITECH PROJECT, 2022
** set_manoir.
** File description:
** set_manoir
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void set_layer(map_t *map_struct, char *texture,
               char *csv_map, int width, int i);

int set_manoir(my_rpg_t *rpg)
{
    if ((rpg->maps->maps[TM_MANOIR] = malloc(sizeof(map_t) *
    (L_MANOIR + 1))) == NULL)
        return (ERROR);
    for (int i = 0; i != MANOIR_LAYERS; ++i)
        set_layer(&rpg->maps->maps[TM_MANOIR][i], "assets/Interior_1.png",
        rpg->maps->csv[CSV_MANOIR].layers[i].name, 1984 , 0);
    return (SUCCESS);
}
