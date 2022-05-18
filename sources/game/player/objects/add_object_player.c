/*
** EPITECH PROJECT, 2022
** add_object_player.C
** File description:
** add_object_player
*/

#include "my_rpg.h"
#include "my_macro.h"

void add_object_player(my_rpg_t *rpg, objects_t *object_add, int emplacement)
{
    rpg->player->objects[emplacement].object = *object_add;
    rpg->player->objects[emplacement].owned = sfFalse;
    rpg->player->objects[emplacement].used = sfFalse;
}