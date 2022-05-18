/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Read Map header
*/

#ifndef READ_MAP_H
    #define READ_MAP_H

#include "my_rpg.h"

int read_file(char * const filepath, map_t *map_struct);
void create_sprite_map(map_t *map_struct, int mult);

#endif /* !READ_MAP_H */