/*
** EPITECH PROJECT, 2022
** set_colision.c
** File description:
** set_colision
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my_lib.h"
#include "my_rpg.h"

char **my_str_to_word_array(char *str, char p_break);

static int is_case_colisionable(int tuile)
{
    for (int i = 0; i != MANOIR_NB_ID_COLISION; ++i)
        if (tuile != -1)
            return (SUCCESS);
    return (ERROR);
}

static int check_line_colision(char *files_csv_str, int **ret_colision, int y)
{
    char **numbers = my_str_to_word_array(files_csv_str, ',');

    for (int i = 0; numbers[i] != NULL; ++i)
        if (is_case_colisionable(my_atoi(numbers[i]))
        == SUCCESS)
            ret_colision[y][i] = -1;
}

int **find_colision(char **file_csv, int **ret_colision)
{
    for (int y = 0; file_csv[y] != NULL; ++y)
        check_line_colision(file_csv[y], ret_colision, y);
}

int **get_colision(csv_layer_name_t *csv, int len_csv, int len_csv_line,
int nb_layers)
{
    int **ret = create_array_int(len_csv, len_csv_line);
    char **file_csv = NULL;
    char *buffer = NULL;
    int lines = 0;

    for (int i = 0; i != nb_layers; ++i)
        if (csv[i].colisionable == true) {
            buffer = read_file_wo_stat(csv[i].name, &lines);
            file_csv = my_str_to_word_array(buffer, '\n');
            find_colision(file_csv, ret);
        }
    return (ret);
}