/*
** EPITECH PROJECT, 2022
** get_input.c
** File description:
** get_input
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "manager/my_input.h"
#include "player/player_check_input.h"

void get_input(my_rpg_t *rpg)
{
    if (is_input_valide(rpg, rpg->manager->event.key.code) == SUCCESS &&
    rpg->manager->event.type == sfEvtKeyPressed)
        check_player_events_pressed(rpg, rpg->manager->event.key.code);
    if (is_input_valide(rpg, rpg->manager->event.key.code) == SUCCESS &&
    rpg->manager->event.type == sfEvtKeyReleased)
        check_player_events_released(rpg, rpg->manager->event.key.code);
}
