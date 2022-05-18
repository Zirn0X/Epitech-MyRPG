/*
** EPITECH PROJECT, 2022
** maps_colision.h
** File description:
** maps_colision
*/

#ifndef MAPS_COLISION_H_
    #define MAPS_COLISION_H_

typedef struct csv_layer_name_s csv_layer_name_t;

int **get_colision(csv_layer_name_t *csv, int len_csv, int len_csv_line,
int nb_layers);

#endif /* !MAPS_COLISION_H_ */
