/*
** EPITECH PROJECT, 2022
** monsters_deplacement.c
** File description:
** monsters_deplacement
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void bar_life_follow(my_rpg_t *rpg, my_sprite_t *sprite, sfVector2f position);

void monsters_deplacement(my_rpg_t *rpg, my_sprite_t *ennemy, float offset)
{
    if (ennemy->position.y < rpg->player->sprite->position.y)
        ennemy->position.y += offset;
    if (ennemy->position.y > rpg->player->sprite->position.y)
        ennemy->position.y -= offset;
    if (ennemy->position.x < rpg->player->sprite->position.x)
        ennemy->position.x += offset;
    if (ennemy->position.x > rpg->player->sprite->position.x)
        ennemy->position.x -= offset;
    sfSprite_setPosition(ennemy->sprite, ennemy->position);
    bar_life_follow(rpg, ennemy, (sfVector2f)
    {ennemy->position.x - 20, ennemy->position.y - 20});
}