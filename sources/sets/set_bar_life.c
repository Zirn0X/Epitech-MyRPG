/*
** EPITECH PROJECT, 2022
** set_bar_life.c
** File description:
** set_bar_life
*/

#include "my_rpg.h"
#include "my_macro.h"

void set_bar_life(my_sprite_t *sprite, sfVector2f size, sfVector2f position,
sfColor color)
{
    sprite->bar_life = sfRectangleShape_create();
    sfRectangleShape_setSize(sprite->bar_life, size);
    sfRectangleShape_setFillColor(sprite->bar_life, color);
    sfRectangleShape_setPosition(sprite->bar_life, position);
}