/*
** EPITECH PROJECT, 2022
** set_tecture_rectangle_shape.c
** File description:
** set_texture_rectangle_shape.c
*/

#include <SFML/Graphics.h>

void set_texture_sprite(sfSprite **sprite, sfTexture *texture,
char *file_texture, sfIntRect rect)
{
    *sprite = sfSprite_create();
    texture = sfTexture_createFromFile(file_texture, NULL);
    sfSprite_setTexture(*sprite, texture, sfTrue);
    sfSprite_setTextureRect(*sprite, rect);
    return;
}
