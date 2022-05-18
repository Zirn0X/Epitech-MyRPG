/*
** EPITECH PROJECT, 2022
** Solo Stumper
** File description:
** Strcmp
*/

#include <stdlib.h>

int sum_str(char const *str)
{
    int i = 0;
    int result = 0;

    while (str[i] != '\0') {
        result += str[i];
        i++;
    }
    return result;
}

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL)
        return (-1);
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            return (1);
        } else if (str1[i] < str2[i]) {
            return (-1);
        } else {
            i++;
        }
    }
    return 0;
}
