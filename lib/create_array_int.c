/*
** EPITECH PROJECT, 2022
** create_array_int.c
** File description:
** create_array_int
*/

#include <stdlib.h>

int **create_array_int(int len_array, int len_lines)
{
    int **ret = malloc(sizeof(int *) * (len_array + 1));

    for (int i = 0; i != len_array; ++i)
        ret[i] = malloc(sizeof(int) * (len_lines + 1));
    for (int i = 0; i != len_array; ++i) {
        for (int j = 0; j != len_lines; ++j)
            ret[i][j] = 1;
    }
    return (ret);
}