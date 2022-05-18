/*
** EPITECH PROJECT, 2022
** set_events.c
** File description:
** set_events.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "menu/home_menu_events.h"

int set_events_menu(void (***function)(my_rpg_t *rpg))
{
    if ((function[0] = malloc(sizeof(int *) * NB_MENU_SCENES)) == NULL)
        return (ERROR);
    function[0][0] = &(home_page_event);
    function[0][1] = &(setting_home_event);
    function[0][2] = &(save_page_event);
    return (SUCCESS);
}