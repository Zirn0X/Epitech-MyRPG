/*
** EPITECH PROJECT, 2022
** set_scenes.c
** File description:
** set_scenes
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "menu/home_menu_scenes.h"

int set_scenes_menu(int (***function)(my_rpg_t *rpg))
{
    if ((function[0] = malloc(sizeof(int *) * NB_MENU_SCENES)) == NULL)
        return (ERROR);
    function[0][0] = &(home_page);
    function[0][1] = &(setting_page);
    function[0][2] = &(save_page);
    return (SUCCESS);
}