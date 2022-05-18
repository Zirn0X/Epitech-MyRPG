/*
** EPITECH PROJECT, 2022
** my_player.c
** File description:
** my_player
*/

#include "my_rpg.h"
#include "my_macro.h"

void player_events(my_rpg_t *rpg);

void my_player(my_rpg_t *rpg)
{
    if (rpg->player->objects[0].used == sfTrue)
        sfRenderWindow_drawSprite(rpg->manager->window,
        rpg->player->sprite->sprite, NULL);
    player_events(rpg);
}