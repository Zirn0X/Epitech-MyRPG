/*
** EPITECH PROJECT, 2022
** search_spawner.c
** File description:
** search_spawner
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

int search_line_by_line(char *line, int csv_spawner)
{
    char **line_data_2d = my_str_to_word_array(line, ',');

    for (int x = 0; line_data_2d[x] != NULL; ++x) {
        if (my_atoi(line_data_2d[x]) == csv_spawner)
            return (x);
    }
    return (ERROR);
}

void search_spawner(my_rpg_t *rpg, int type_spawner, int csv_spawner)
{
    int lines = 0;
    char *data_csv = read_file_wo_stat("assets/csv/exterior_Spawner.csv",
    &lines);
    char **data_csv_2d = my_str_to_word_array(data_csv, '\n');

    for (int y = 0, x = 0; data_csv_2d[y] != NULL; ++y, x = 0) {
        x = search_line_by_line(data_csv_2d[y], csv_spawner);
        if (x != ERROR) {
            rpg->monsters->spawner[type_spawner].pos.y = (float)y *
            (TUILE_SIZE * MULTIPLICATOR_SIZE);
            rpg->monsters->spawner[type_spawner].pos.x = (float)x *
            (TUILE_SIZE * MULTIPLICATOR_SIZE);
        }
    }
}
