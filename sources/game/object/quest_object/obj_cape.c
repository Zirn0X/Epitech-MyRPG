/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** obj_cape
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "objects/object_utils.h"

static void get_event_obj_cape(my_rpg_t *rpg, sfEventType event, int i)
{
    char *string = "assets/object/obj_cape.png";

    if (event == sfEvtKeyPressed && rpg->manager->event.key.code == sfKeyE) {
        rpg->all_objects->quest_obj[i].nb_cape_get = 1;
        add_to_inventory(rpg, rpg->all_objects->cape, string, 6);
    }
}

void display_quest_cape(my_rpg_t *rpg, all_objects_t *all_objects)
{
    sfVector2f pos;

    for (int i = 0; i != NB_CAPE; i++) {
        if (all_objects->quest_obj[i].nb_cape_get != 0)
            continue;
        pos.x = all_objects->quest_obj[i].cape->pos.x;
        pos.y = all_objects->quest_obj[i].cape->pos.y;
        sfRenderWindow_drawRectangleShape(rpg->manager->window,
        all_objects->quest_obj[i].cape->rect, sfFalse);
        if (rpg->player->sprite->position.x >= pos.x - 120 && rpg->player->sprite->position.x <= pos.x
        && rpg->player->sprite->position.y >= pos.y - 120 && rpg->player->sprite->position.y <= pos.y)
            get_event_obj_cape(rpg, sfEvtKeyPressed, i);
    }
}