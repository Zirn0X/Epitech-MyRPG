/*
** EPITECH PROJECT, 2022
** set_menu.c
** File description:
** set_menu
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "menu/my_sets.h"

int set_menu(my_rpg_t *rpg)
{
    if (set_home_menu(rpg) == ERROR)
        return (ERROR);
    if (set_home_setting(rpg) == ERROR)
        return (ERROR);
    if (set_home_save(rpg) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
