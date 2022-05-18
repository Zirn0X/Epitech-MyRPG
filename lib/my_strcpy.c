/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** my_strcpy
*/

#include <stdlib.h>

int my_strlen(char const *len);

void my_strcpy(char *dest, char const *src)
{
    int fin = 0;
    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    for (int i = 0; i != my_strlen(src); i++) {
        dest[i] = src[i];
        fin += 1;
    }
    dest[fin] = '\0';
    return;
}
