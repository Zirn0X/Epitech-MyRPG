/*
** EPITECH PROJECT, 2022
** object_is_have.c
** File description:
** object_is_have
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

int is_object_owned(my_rpg_t *rpg, objects_t *object_src)
{
    for (int i = 0; i != NB_PLAYER_OBJECTS; ++i) {
        if (my_strcmp(rpg->player->objects[i].object.name, object_src->name) == 0)
            return (SUCCESS);
    }
    return (ERROR);
}