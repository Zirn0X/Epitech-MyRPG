/*
** EPITECH PROJECT, 2022
** set_layer.c
** File description:
** set_layer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

int read_file(char * const filepath, map_t *map_struct);
void create_sprite_map(map_t *map_struct, int i);

void set_layer(map_t *map_struct, char *texture,
char *csv_map, int width, int i)
{
    map_struct->sprite_texture = texture;
    map_struct->csv_map = csv_map;
    map_struct->width = width;
    read_file(map_struct->csv_map, map_struct);
    create_sprite_map(map_struct, i);
}
