/*
** EPITECH PROJECT, 2022
** set_cursor.c
** File description:
** set_cursor
*/

#include "my_rpg.h"

void set_cursor(my_rpg_t *rpg)
{
    rpg->home_menu->sprite_cursor = sfSprite_create();
    rpg->home_menu->texture_cursor = sfTexture_createFromFile
    ("assets/cursor.png", NULL);
    sfSprite_setTexture(rpg->home_menu->sprite_cursor,
    rpg->home_menu->texture_cursor, sfFalse);
    sfSprite_setScale
    (rpg->home_menu->sprite_cursor, (sfVector2f) {0.15, 0.15});
    sfRenderWindow_setMouseCursorVisible(rpg->manager->window, sfFalse);
}