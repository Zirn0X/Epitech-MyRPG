/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_paper
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"
#include "objects/quest_function.h"

void set_pos_obj_paper(all_objects_t *all_objects)
{
    all_objects->quest_obj[0].paper->pos = (sfVector2f) {1246, 5761};
    all_objects->quest_obj[1].paper->pos = (sfVector2f) {2989, 5052};
    all_objects->quest_obj[2].paper->pos = (sfVector2f) {2350, 5848};
    for (int i = 0; i != NB_PAPER; i++)
        sfRectangleShape_setPosition(all_objects->quest_obj[i].paper->rect,
        all_objects->quest_obj[i].paper->pos);
}

void initialize_obj_paper(my_rpg_t *rpg, int i)
{
    rpg->all_objects->quest_obj[i].nb_paper_get = 0;
    rpg->all_objects->quest_obj[i].paper =
    create_object("paper", 1, 100, 1);
    rpg->all_objects->quest_obj[i].paper->flag = 'P';
    rpg->all_objects->quest_obj[i].paper->rect = sfRectangleShape_create();
    rpg->all_objects->quest_obj[i].paper->texture =
    sfTexture_createFromFile("assets/object/obj_paper.png", NULL);
    sfRectangleShape_setSize(rpg->all_objects->quest_obj[i].paper->rect,
    (sfVector2f) {50, 50});
    sfRectangleShape_setTexture(rpg->all_objects->quest_obj[i].paper->rect,
    rpg->all_objects->quest_obj[i].paper->texture, sfFalse);
    sfRectangleShape_setScale
    (rpg->all_objects->quest_obj[i].paper->rect, (sfVector2f) {1.1, 1.1});
}
