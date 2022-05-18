/*
** EPITECH PROJECT, 2022
** read_file_w_stat.c
** File description:
** read_file_w_stat
*/

#include <stdio.h>
#include <stdlib.h>

char *my_strcat(char *str1, char *str2);
FILE *open_file(char * const pathfile);

static char *fill_buffer(char *path, FILE *fp, int *lines)
{
    size_t size = 0;
    char *buffer = NULL;
    char *file = NULL;

    file = malloc(sizeof(char));
    if (file == NULL)
        return NULL;
    file[0] = '\0';
    for (; getline(&buffer, &size, fp) != -1; *lines += 1)
        file = my_strcat(file, buffer);
    return file;
}

char *read_file_wo_stat(char * const pathfile, int *lines)
{
    FILE *fp = open_file(pathfile);
    char *buffer = fill_buffer(pathfile, fp, lines);

    if (buffer == NULL || buffer[0] == '\0')
        return (NULL);
    if (fclose(fp) == -1)
        return (NULL);
    return (buffer);
}
