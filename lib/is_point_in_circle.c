/*
** EPITECH PROJECT, 2022
** is_point_in_circle.c
** File description:
** is_point_in_circle
*/

#include <math.h>
#include <stdbool.h>

bool is_point_in_circle(float *pos_point, float pos_y_circle,
float pos_x_circle, float range)
{
    float rayon_x = 0;
    float rayon_y = 0;
    float rayon = 0;

    rayon_x = pos_x_circle - pos_point[0];
    rayon_y = pos_y_circle - pos_point[1];
    rayon = sqrt((rayon_x * rayon_x) + (rayon_y * rayon_y));
    if (rayon <= range)
        return (1);
    return (0);
}