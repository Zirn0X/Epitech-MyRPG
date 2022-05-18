/*
** EPITECH PROJECT, 2022
** my_free_array.c
** File description:
** my_free_array
*/

#include <stdlib.h>

void my_free_array(char **array)
{
    int i = 0;

    for (; array[i] != NULL; ++i)
        free(array[i]);
    free(array[i]);
    free(array);
    return;
}
