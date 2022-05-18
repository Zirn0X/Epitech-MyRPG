/*
** EPITECH PROJECT, 2022
** open_file.c
** File description:
** open_file
*/

#include <stdio.h>
#include <stddef.h>

FILE *open_file(char * const pathfile)
{
    FILE *file = NULL;

    file = fopen(pathfile, "r");
    if (!file)
        return NULL;
    return (file);
}