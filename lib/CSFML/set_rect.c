/*
** EPITECH PROJECT, 2022
** set_rect.c
** File description:
** set_rect
*/

#include <SFML/Graphics.h>

sfIntRect set_rect(int width, int left, int top, int height)
{
    sfIntRect rect;

    rect.width = height;
    rect.left = left;
    rect.top = top;
    rect.height = height;
    return (rect);
}