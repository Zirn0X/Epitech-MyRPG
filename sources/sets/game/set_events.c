/*
** EPITECH PROJECT, 2022
** set_game_events.c
** File description:
** set_game_events
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "game/game_events.h"

int set_events_game(void (***function)(my_rpg_t *rpg))
{
    if ((function[0] = malloc(sizeof(int *) * NB_GAME_SCENES)) == NULL)
        return (ERROR);
    function[0][0] = &(room_events);
    function[0][1] = &(competencies_event);
    function[0][2] = &(pause_events);
    function[0][3] = &(exterior_events);
    return (SUCCESS);
}