/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Set CSV Cave
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"
#include "map/maps_colision.h"
#include "my_rpg.h"

static void set_names_layers_param_cave(csv_t *csv)
{
    csv->layers = malloc(sizeof(csv_layer_name_t) * (CAVE_LAYER + 1));
    csv->layers[0].name = "assets/csv/grotte_Background.csv";
    csv->layers[1].name = "assets/csv/grotte_Colision.csv";
    csv->layers[0].colisionable = false;
    csv->layers[1].colisionable = false;
}

static void set_map_colision_cave(csv_t *csv)
{
    csv->colision = get_colision(csv->layers, CAVE_LEN_CSV,
                                 CAVE_LEN_CSV_LINE, CAVE_LAYER);
}

void set_csv_cave(csv_t *csv, int len_csv, int len_csv_lines)
{
    set_names_layers_param_cave(csv);
    set_map_colision_cave(csv);
    csv->len_csv = len_csv;
    csv->len_csv_line = len_csv_lines;
}
