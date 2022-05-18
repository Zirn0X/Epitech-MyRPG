/*
** EPITECH PROJECT, 2022
** set_csv_exteriors.c
** File description:
** set_csv_exteriors
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"
#include "map/maps_colision.h"

static void set_names_layers_param_exteriors(csv_t *csv)
{
    csv->layers = malloc(sizeof(csv_layer_name_t) * (EXTERIORS_LAYER + 1));
    csv->layers[0].name = "assets/csv/exterior_Background.csv";
    csv->layers[1].name = "assets/csv/exterior_No_colision.csv";
    csv->layers[2].name = "assets/csv/exterior_Colision.csv";
    csv->layers[0].colisionable = false;
    csv->layers[1].colisionable = false;
    csv->layers[2].colisionable = true;
}

static void set_map_colision_exteriors(csv_t *csv)
{
    csv->colision = get_colision(csv->layers, EXTERIORS_LEN_CSV,
    EXTERIORS_LEN_CSV_LINE, EXTERIORS_LAYER);
}

void set_csv_exteriors(csv_t *csv, int len_csv, int len_csv_lines)
{
    set_names_layers_param_exteriors(csv);
    set_map_colision_exteriors(csv);
    csv->len_csv = len_csv;
    csv->len_csv_line = len_csv_lines;
}