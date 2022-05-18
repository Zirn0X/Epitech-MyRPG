/*
** EPITECH PROJECT, 2022
** my_rpg.c
** File description:
** my_rpg
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_home_menu.h"
#include "my_macro.h"
#include "map/read_map.h"
#include "my_lib.h"

int my_game(my_rpg_t *rpg);
int set_all(my_rpg_t *rpg);

static int malloc_primary_struct(my_rpg_t *rpg)
{
    if ((rpg->home_menu = malloc(sizeof(interface_t))) == NULL)
        return (ERROR);
    if ((rpg->home_setting = malloc(sizeof(interface_t))) == NULL)
        return (ERROR);
    if ((rpg->home_save = malloc(sizeof(interface_t))) == NULL)
        return (ERROR);
    if ((rpg->manager = malloc(sizeof(manager_t))) == NULL)
        return (ERROR);
    if ((rpg->game = malloc(sizeof(game_t))) == NULL)
        return (ERROR);
    if ((rpg->scenes = malloc(sizeof(scenes_t))) == NULL)
        return (ERROR);
    if ((rpg->player = malloc(sizeof(my_player_t))) == NULL)
        return (ERROR);
    if ((rpg->maps = malloc(sizeof(maps_t))) == NULL)
        return (ERROR);
    if ((rpg->all_texture = malloc(sizeof(textures_t))) == NULL)
        return (ERROR);
    if ((rpg->effects = malloc(sizeof(effect_t))) == NULL)
        return (ERROR);
    if ((rpg->all_objects = malloc(sizeof(all_objects_t))) == NULL)
        return (ERROR);
    if ((rpg->menu_competencies =
    malloc(sizeof(competencies_interface_t))) == NULL)
        return ERROR;
    if ((rpg->monsters = malloc(sizeof(monster_t))) == NULL)
        return (ERROR);
    if ((rpg->npcs = malloc(sizeof(npc_t))) == NULL)
        return (ERROR);
    if ((rpg->chatbox = malloc(sizeof(chatbox_t) * 3)) == NULL)
        return (ERROR);
    if ((rpg->quests = malloc(sizeof(quest_t) * NB_QUESTS)) == NULL)
        return (ERROR);
    return(SUCCESS);
}

int my_rpg(void)
{
    my_rpg_t *rpg = malloc(sizeof(my_rpg_t));

    if (malloc_primary_struct(rpg) == ERROR)
        return (ERROR);
    if (set_all(rpg) == ERROR)
        return (ERROR);
    my_game(rpg);
    return (SUCCESS);
}