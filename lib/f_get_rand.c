/*
** EPITECH PROJECT, 2022
** f_get_rand
** File description:
** f_get_rand
*/

#include <stdlib.h>

int f_get_rand(int min, int max)
{
    if (min == max)
        return (min);
    return (min + (rand() % (max - min + 1)));
}

// float f_get_rand_float(float min, float max)
// {
//     if (min == max)
//         return (min);
//     return (min + ((float)rand() % (max - min + 1)));
// }
