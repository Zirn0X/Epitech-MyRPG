/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** function that count the number of characters
*/

#include <stdlib.h>

int my_strlen(char const *len)
{
    int i = 0;

    if (len == NULL)
        return (0);
    while (len[i] != '\0')
        i = i + 1;
    return (i);
}
