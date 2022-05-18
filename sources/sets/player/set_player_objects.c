/*
** EPITECH PROJECT, 2022
** set_players_objects.c
** File description:
** set_player_objects
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "game/player/player_objects.h"

void set_player_objects(my_rpg_t *rpg)
{
    rpg->player->objects = malloc(sizeof(player_objects_t) * NB_PLAYER_OBJECTS);
    for (int i = 0; i != NB_PLAYER_OBJECTS; ++i) {
        rpg->player->objects[i].object.name = NULL;
        rpg->player->objects[i].flag = ' ';
        rpg->player->objects[i].object.quantity = 0;
        rpg->player->objects[i].object.durability = 0;
        rpg->player->objects[i].object.damage = 0;
        rpg->player->objects[i].used = sfFalse;
        rpg->player->objects[i].owned = sfFalse;
    }
}
