/*
** EPITECH PROJECT, 2022
** display_effects.c
** File description:
** display_effects
*/

#include "my_rpg.h"
#include "my_macro.h"

void display_effects(my_rpg_t *rpg)
{
    if (rpg->player->objects[0].used == sfFalse) {
        sfRenderWindow_drawSprite(rpg->manager->window,
        rpg->player->sprite->sprite, NULL);
        sfRenderWindow_drawSprite(rpg->manager->window,
        rpg->effects->shadow->sprite, NULL);
    } else
        sfRenderWindow_drawSprite(rpg->manager->window,
        rpg->effects->lanthern->sprite, NULL);
}