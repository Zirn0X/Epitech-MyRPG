/*
** EPITECH PROJECT, 2022
** preset_home_menu_preset.c
** File description:
** preset_home_menu_scenes
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "menu/home_menu_scenes.h"

int set_scenes_menu(int (***function)(my_rpg_t *rpg));
int set_events_menu(void (***function)(my_rpg_t *rpg));

int set_home_menu_scenes(my_rpg_t *rpg)
{
    int (**scenes) (my_rpg_t *rpg);
    void (**events) (my_rpg_t *rpg);

    if (set_scenes_menu(&scenes) == ERROR || set_events_menu(&events) == ERROR)
        return (ERROR);
    rpg->scenes->scenes[TYPE_MENU] = malloc(sizeof(int *) * NB_MENU_SCENES);
    rpg->scenes->events[TYPE_MENU] = malloc(sizeof(void *) * NB_MENU_SCENES);
    for (int i = 0; i != NB_MENU_SCENES; ++i) {
        rpg->scenes->scenes[TYPE_MENU][i] = scenes[i];
        rpg->scenes->events[TYPE_MENU][i] = events[i];
    }
    return (SUCCESS);
}
