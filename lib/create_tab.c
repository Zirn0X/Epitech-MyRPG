/*
** EPITECH PROJECT, 2022
** create_tab.c
** File description:
** create_tab
*/

#include <stdarg.h>
#include <stdlib.h>

char **create_tab(int nb_str, ...)
{
    va_list list;
    char **ret = malloc(sizeof(sizeof(char *)) * (nb_str + 1));

    va_start(list, nb_str);
    for (int i = 0; i != nb_str; ++i)
        ret[i] = va_arg(list, char *);
    va_end(list);
    ret[nb_str] = NULL;
    return (ret);
}
