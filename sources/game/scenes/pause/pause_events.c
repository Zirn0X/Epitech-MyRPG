/*
** EPITECH PROJECT, 2022
** pause_events.c
** File description:
** pause_events
*/

#include "my_rpg.h"
#include "my_macro.h"

static void check_case_pause(my_rpg_t *rpg)
{
    if (rpg->manager->event.type == sfEvtKeyPressed
    && rpg->manager->event.key.code == sfKeySpace
    && rpg->scenes->sub_scenes == S_PAUSE && rpg->pause->id == 0) {
        rpg->manager->end = QUIT;
        rpg->pause->id = 1;
    }
    if (rpg->manager->event.type == sfEvtKeyPressed
    && rpg->manager->event.key.code == sfKeySpace
    && rpg->scenes->sub_scenes == S_PAUSE && rpg->pause->id == 1)
        rpg->scenes->sub_scenes = rpg->current_sub;
    if (rpg->manager->event.type == sfEvtKeyPressed
    && rpg->manager->event.key.code == sfKeySpace
    && rpg->scenes->sub_scenes == S_PAUSE && rpg->pause->id == 2) {
        rpg->scenes->type_scenes = TYPE_MENU;
        rpg->scenes->sub_scenes = HOME_PAGE;
    }
}

void pause_events(my_rpg_t *rpg)
{
    check_case_pause(rpg);
    if (rpg->manager->event.type == sfEvtKeyPressed
    && rpg->manager->event.key.code == sfKeyRight && rpg->pause->id < 2)
        rpg->pause->id++;
    if (rpg->manager->event.type == sfEvtKeyPressed
    && rpg->manager->event.key.code == sfKeyLeft && rpg->pause->id > 0)
        rpg->pause->id--;
}
