/*
** EPITECH PROJECT, 2022
** shadow_effect.c
** File description:
** shadow_effect
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my_rpg.h"
#include "my_lib.h"

int set_shadow_effect(my_rpg_t *rpg)
{
    if ((rpg->effects->shadow = malloc(sizeof(my_sprite_t))) == NULL)
        return (ERROR);
    rpg->effects->shadow->position.x = rpg->player->sprite->position.x;
    rpg->effects->shadow->position.y = rpg->player->sprite->position.y;
    create_sprite(&(rpg->effects->shadow->sprite),
    &(rpg->effects->shadow->texture), rpg->effects->shadow->position,
    "assets/effects/lamp_light.png");
    sfSprite_setScale(rpg->effects->shadow->sprite, (sfVector2f)
    {4.5, 4.0});
    rpg->effects->darkest = 238;
    sfSprite_setColor(rpg->effects->shadow->sprite, (sfColor) {0, 0, 0,
    rpg->effects->darkest});
    return (SUCCESS);
}
