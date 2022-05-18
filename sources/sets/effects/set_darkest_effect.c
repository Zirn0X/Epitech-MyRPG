/*
** EPITECH PROJECT, 2022
** set_darkets_effect.c
** File description:
** set_darkest_effect
*/

#include <stddef.h>
#include "my_macro.h"
#include "my_rpg.h"

int set_lanthern_effect(my_rpg_t *rpg)
{
    if ((rpg->effects->lanthern = malloc(sizeof(my_sprite_t))) == NULL)
        return (ERROR);
    rpg->effects->lanthern->position.x = rpg->player->sprite->position.x;
    rpg->effects->lanthern->position.y = rpg->player->sprite->position.y;
    create_sprite(&(rpg->effects->lanthern->sprite),
    &(rpg->effects->lanthern->texture), rpg->effects->lanthern->position,
    "assets/effects/lanthern_up.png");
    sfSprite_setScale(rpg->effects->lanthern->sprite, (sfVector2f) {4.5,
    4.0});
    sfSprite_setColor(rpg->effects->lanthern->sprite, (sfColor) {255, 255, 255, 255});
    return (SUCCESS);
}