/*
** EPITECH PROJECT, 2022
** preset__all.c
** File description:
** preset_all
*/

#include "my_rpg.h"
#include "my_sets.h"
#include "my_macro.h"

int set_chatbox(my_rpg_t *rpg);

int set_all(my_rpg_t *rpg)
{
    if (set_all_scenes(rpg) == ERROR)
        return (ERROR);
    if (set_menu(rpg) == ERROR)
        return (ERROR);
    if (set_game(rpg) == ERROR)
        return (ERROR);
    if (set_player(rpg) == ERROR)
        return (ERROR);
    set_manager(rpg);
    if (set_csv(rpg) == ERROR)
        return (ERROR);
    if (set_all_maps(rpg) == ERROR)
        return (ERROR);
    if (set_effects(rpg) == ERROR)
        return (ERROR);
    if (set_objects(rpg) == ERROR)
        return (ERROR);
    if (set_spawners(rpg) == ERROR)
        return(ERROR);
    if (set_competencies(rpg) == ERROR)
        return (ERROR);
    if (set_inventory(rpg) == ERROR)
        return (ERROR);
    if (set_pause(rpg) == ERROR)
        return (ERROR);
    if (set_monsters(rpg) == ERROR)
        return (ERROR);
    if (set_npcs(rpg) == ERROR)
        return (ERROR);
    if (set_chatbox(rpg) == ERROR)
        return (ERROR);
    if (set_quests(rpg) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
