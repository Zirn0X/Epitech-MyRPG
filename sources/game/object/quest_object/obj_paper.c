/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** obj_paper
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "objects/object_utils.h"

static void get_event_obj_paper(my_rpg_t *rpg, sfEventType event, int i)
{
    char *string = "assets/object/obj_paper.png";

    if (event == sfEvtKeyPressed && rpg->manager->event.key.code == sfKeyE) {
        rpg->all_objects->quest_obj[i].nb_paper_get = 1;
        add_to_inventory(rpg, rpg->all_objects->paper, string, 6);
    }
}

void display_quest_paper(my_rpg_t *rpg, all_objects_t *all_objects)
{
    sfVector2f pos;

    for (int i = 0; i != NB_PAPER; i++) {
        if (all_objects->quest_obj[i].nb_paper_get != 0)
            continue;
        pos.x = all_objects->quest_obj[i].paper->pos.x;
        pos.y = all_objects->quest_obj[i].paper->pos.y;
        sfRenderWindow_drawRectangleShape(rpg->manager->window,
        all_objects->quest_obj[i].paper->rect, sfFalse);
        if (rpg->player->sprite->position.x >= pos.x - 120 && rpg->player->sprite->position.x <= pos.x
        && rpg->player->sprite->position.y >= pos.y - 120 && rpg->player->sprite->position.y <= pos.y)
            get_event_obj_paper(rpg, sfEvtKeyPressed, i);
    }
}