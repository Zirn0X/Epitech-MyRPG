/*
** EPITECH PROJECT, 2022
** move_rect.c
** File description:
** move_rect
*/

#include <SFML/Graphics.h>

void move_rect(sfIntRect *rect, int offset, int max_value, int min)
{
    if (rect->left < max_value) {
        rect->left += offset;
    } else {
        rect->left = min;
    }
}