/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_quest_object
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my_macro.h"
#include "objects/quest_function.h"

int set_quest_object(my_rpg_t *rpg)
{
    if ((rpg->all_objects->quest_obj = malloc(sizeof(quest_object_t) * 10)) == NULL)
        return (ERROR);
    for (int i = 0; i != NB_MUSHROOM; i++)
        initialize_obj_mushroom(rpg, i);
    for (int i = 0; i != NB_PAPER; i++)
        initialize_obj_paper(rpg, i);
    for (int i = 0; i != NB_CAPE; i++)
        initialize_obj_cape(rpg, i);
    set_pos_obj_mushroom(rpg->all_objects);
    set_pos_obj_paper(rpg->all_objects);
    set_pos_obj_cape(rpg->all_objects);
}