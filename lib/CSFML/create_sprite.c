/*
** EPITECH PROJECT, 2022
** create_sprite.c
** File description:
** create_sprite
*/

#include <SFML/Graphics.h>

void create_sprite(sfSprite **sprite, sfTexture **texture, sfVector2f position,
char * const path_file)
{
    *sprite = sfSprite_create();
    *texture = sfTexture_createFromFile(path_file, NULL);
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setPosition(*sprite, position);
    return;
}