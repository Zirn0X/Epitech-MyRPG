/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Read File
*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_macro.h"
#include "my_lib.h"
#include "map/read_map.h"

int char_dd_to_int_dd(map_t *map)
{
    int **map_int = malloc(sizeof(int *) * (map->lines + 1));
    char **first_line = my_str_to_word_array(map->char_map_array[0], ',');
    int col = 0;
    int y = 0;
    int i = 0;
    int j = 0;

    if (first_line == NULL)
        return ERROR_RETURN;
    for (; first_line[i]; i++, col++);
    map->cols = col;
    for (i = 0; i < map->lines; i++) {
        first_line = my_str_to_word_array(map->char_map_array[i], ',');
        map_int[i] = malloc(sizeof(int) * (col + 1));
        for (j = 0; j < map->cols; j++, y++)
            map_int[i][j] = my_getnbr(first_line[y]);
        y = 0;
    }
    map_int[i] = NULL;
    map->int_map_array = map_int;
    return 0;
}

int read_file(char * const filepath, map_t *map_struct)
{
    char *buff = NULL;

    map_struct->lines = 0;
    buff = read_file_wo_stat(filepath, &map_struct->lines);
    map_struct->char_map_array = my_str_to_word_array(buff, '\n');
    if (map_struct->char_map_array == NULL)
        return ERROR_RETURN;
    char_dd_to_int_dd(map_struct);
    return 0;
}
