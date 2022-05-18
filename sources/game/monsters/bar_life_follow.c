/*
** EPITECH PROJECT, 2022
** bar_life_follow.c
** File description:
** bar_life_follow
*/

#include "my_rpg.h"
#include "my_macro.h"

void bar_life_follow(my_rpg_t *rpg, my_sprite_t *sprite, sfVector2f position)
{
    sfRectangleShape_setPosition(sprite->bar_life, position);
}