/*
** EPITECH PROJECT, 2022
** preset_scenes.c
** File description:
** preset_scenes
*/

#include <stdlib.h>
#include "game/game_scenes.h"
#include "my_rpg.h"
#include "my_macro.h"

int set_events_game(void (***function)(my_rpg_t *rpg));
int set_scenes_game(int (***function)(my_rpg_t *rpg));

int set_game_scenes(my_rpg_t *rpg)
{
    int (**scenes)(my_rpg_t *rpg);
    void (**events) (my_rpg_t *rpg);

    if (set_scenes_game(&scenes) == ERROR || set_events_game(&events) == ERROR)
        return (ERROR);
    rpg->scenes->scenes[TYPE_GAME] = malloc(sizeof(int *) * NB_GAME_SCENES);
    rpg->scenes->events[TYPE_GAME] = malloc(sizeof(void *) * NB_GAME_SCENES);
    for (int i = 0; i != NB_GAME_SCENES; ++i) {
        rpg->scenes->scenes[TYPE_GAME][i] = scenes[i];
        rpg->scenes->events[TYPE_GAME][i] = events[i];
    }
    return (SUCCESS);
}