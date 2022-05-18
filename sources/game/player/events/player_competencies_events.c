/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Player Competencies Events
*/

#include "my_rpg.h"
#include "my_macro.h"

void player_inventory_competencies(my_rpg_t *rpg, sfEventType event, int key)
{
    sfVector2i pos;
    if (event == sfEvtKeyPressed && key == KEY_COMPETENCIES
    && rpg->scenes->sub_scenes != S_COMPETENCIES
    && rpg->scenes->sub_scenes == S_MANOIR)
        rpg->game->scenes = S_COMPETENCIES;
    if (event == sfEvtKeyPressed && key == KEY_ESCAPE) {
        rpg->player->compentencies->id = 0;
        rpg->game->scenes = rpg->current_sub;
    }
}