/*
** EPITECH PROJECT, 2022
** set_csv_manoir.c
** File description:
** set_csv_manoir
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"
#include "map/maps_colision.h"


void set_names_layers_param_manoir(csv_t *csv)
{
    csv->layers = malloc(sizeof(csv_layer_name_t) * (MANOIR_LAYERS + 1));
    csv->layers[0].name = "assets/csv/manoir_Floor.csv";
    csv->layers[1].name = "assets/csv/manoir_Walls_Colision.csv";
    csv->layers[2].name = "assets/csv/manoir_Interiors_No_Colision.csv";
    csv->layers[3].name = "assets/csv/manoir_Interiors_Colision.csv";
    csv->layers[0].colisionable = false;
    csv->layers[1].colisionable = true;
    csv->layers[2].colisionable = false;
    csv->layers[3].colisionable = true;
}

void set_map_colision_manoir(csv_t *csv)
{
    csv->colision = get_colision(csv->layers, MANOIR_LEN_CSV,
    MANOIR_LEN_CSV_LINE, MANOIR_LAYERS);
}

void set_csv_manoir(csv_t *csv, int len_csv, int len_csv_lines)
{
    set_names_layers_param_manoir(csv);
    set_map_colision_manoir(csv);
    csv->len_csv = len_csv;
    csv->colision_id = create_str_int(MANOIR_NB_ID_COLISION, 5159,
    2991, 2992, 2994, 2995, 5834);
    csv->len_csv_line = len_csv_lines;
}