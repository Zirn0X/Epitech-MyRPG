/*
** EPITECH PROJECT, 2022
** find_player_in_array.c
** File description:
** find_player_in_array
*/

#include "my_macro.h"

int find_tuile(float pos, float size_tuile, float tuile_max)
{
    int i = 0;

    for (; (size_tuile * i) < pos; ++i);
    return (i);
}

int find_player_pos(float pos, int tuile_max, float size_tuile)
{
    int tuile_pos = find_tuile(pos, size_tuile, tuile_max);
    return (tuile_pos);
}