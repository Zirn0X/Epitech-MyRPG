/*
** EPITECH PROJECT, 2022
** preset_scenes.c
** File description:
** preset_scenes
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my_rpg.h"
#include "scenes/my_sets.h"

void set_type_scenes(my_rpg_t *rpg)
{
    set_home_menu_scenes(rpg);
    set_game_scenes(rpg);
}

int set_all_scenes(my_rpg_t *rpg)
{
    if ((rpg->scenes->scenes = malloc(sizeof(void **) * NB_TYPE_SCENES))
    == NULL)
        return (ERROR);
    if ((rpg->scenes->events = malloc(sizeof(void **) * NB_TYPE_SCENES))
    == NULL);
    rpg->scenes->sub_scenes = HOME_PAGE;
    rpg->scenes->type_scenes = TYPE_MENU;
    set_type_scenes(rpg);
    return (SUCCESS);
}
