/*
** EPITECH PROJECT, 2022
** set_csv.c
** File description:
** set_csv
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"
#include "csv/set_csv.h"

int set_csv(my_rpg_t *rpg)
{
    rpg->maps->csv = malloc(sizeof(csv_t) * NB_SCENES_CSV);
    set_csv_manoir(&rpg->maps->csv[CSV_MANOIR], MANOIR_LEN_CSV,
    MANOIR_LEN_CSV_LINE);
    set_csv_exteriors(&rpg->maps->csv[CSV_EXTERIORS], EXTERIORS_LEN_CSV,
    EXTERIORS_LEN_CSV_LINE);
    set_csv_cave(&rpg->maps->csv[CSV_CAVE], CAVE_LEN_CSV,
                 CAVE_LEN_CSV_LINE);
    return (SUCCESS);
}