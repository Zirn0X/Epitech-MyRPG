/*
** EPITECH PROJECT, 2022
** MY RPG
** File description:
** Competencies events
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "player/player_competencies.h"

static void get_case_competencies(my_rpg_t *rpg, int i)
{
    if (rpg->player->compentencies->points >= 1) {
        switch (i) {
            case 0:
                add_point_defense(rpg->player->compentencies, 1);
                rpg->player->compentencies->points -= 1;
                break;
            case 1:
                add_point_attack(rpg->player->compentencies, 1);
                rpg->player->compentencies->points -= 1;
                break;
            case 2:
                add_point_health(rpg->player->compentencies, 1);
                rpg->player->compentencies->points -= 1;
                break;
            case 3:
                add_point_speed(rpg->player->compentencies, 1);
                rpg->player->compentencies->points -= 1;
                break;
            default:
                break;
        }
    }
}

void competencies_event(my_rpg_t *rpg)
{
    if (rpg->manager->event.type == sfEvtKeyPressed
    && rpg->manager->event.key.code == sfKeyEnter)
        get_case_competencies(rpg, rpg->player->compentencies->id);
    if (rpg->manager->event.type == sfEvtKeyPressed
    && rpg->manager->event.key.code == sfKeySpace
    && rpg->scenes->sub_scenes == S_COMPETENCIES) {
        rpg->scenes->sub_scenes = rpg->current_sub;
        rpg->player->compentencies->id = 0;
    }
    if (rpg->manager->event.type == sfEvtKeyPressed
    && rpg->manager->event.key.code == sfKeyRight
    && rpg->player->compentencies->id < 3)
        rpg->player->compentencies->id++;
    if (rpg->manager->event.type == sfEvtKeyPressed
    && rpg->manager->event.key.code == sfKeyLeft
    && rpg->player->compentencies->id > 0)
        rpg->player->compentencies->id--;
}
