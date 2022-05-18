/*
** EPITECH PROJECT, 2022
** create_str_int.c
** File description:
** create_str_int
*/

#include <stdarg.h>
#include <stdlib.h>

int *create_str_int(int nb_int, ...)
{
    va_list list;
    int *ret = malloc(sizeof(int) * (nb_int + 1));

    va_start(list, nb_int);
    for (int i = 0; i != nb_int; ++i)
        ret[i] = va_arg(list, int);
    va_end(list);
    return (ret);
}