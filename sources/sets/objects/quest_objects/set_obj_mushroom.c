/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_obj_mushroom
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"
#include "objects/quest_function.h"

void set_pos_obj_mushroom(all_objects_t *all_objects)
{
    all_objects->quest_obj[0].mushroom->pos = (sfVector2f) {5384, 726};
    all_objects->quest_obj[1].mushroom->pos = (sfVector2f) {4595, 357};
    all_objects->quest_obj[2].mushroom->pos = (sfVector2f) {3952, 779};
    all_objects->quest_obj[3].mushroom->pos = (sfVector2f) {4684, 1246};
    all_objects->quest_obj[4].mushroom->pos = (sfVector2f) {4101, 1557};
    all_objects->quest_obj[5].mushroom->pos = (sfVector2f) {4981, 1238};
    all_objects->quest_obj[6].mushroom->pos = (sfVector2f) {4990, 417};
    all_objects->quest_obj[7].mushroom->pos = (sfVector2f) {3428, 1136};
    all_objects->quest_obj[8].mushroom->pos = (sfVector2f) {4499, 1783};
    all_objects->quest_obj[9].mushroom->pos = (sfVector2f) {5005, 780};
    for (int i = 0; i != NB_MUSHROOM; i++)
        sfRectangleShape_setPosition(all_objects->quest_obj[i].mushroom->rect,
        all_objects->quest_obj[i].mushroom->pos);
}

void initialize_obj_mushroom(my_rpg_t *rpg, int i)
{
    rpg->all_objects->quest_obj[i].nb_mushroom_get = 0;
    rpg->all_objects->quest_obj[i].mushroom = create_object("mushroom", 1, 100, 1);
    rpg->all_objects->quest_obj[i].mushroom->flag = 'M';
    rpg->all_objects->quest_obj[i].mushroom->rect = sfRectangleShape_create();
    rpg->all_objects->quest_obj[i].mushroom->texture =
    sfTexture_createFromFile("assets/object/obj_mushroom.png", NULL);
    sfRectangleShape_setSize(rpg->all_objects->quest_obj[i].mushroom->rect,
    (sfVector2f) {50, 50});
    sfRectangleShape_setTexture(rpg->all_objects->quest_obj[i].mushroom->rect,
    rpg->all_objects->quest_obj[i].mushroom->texture, sfFalse);
    sfRectangleShape_setScale
    (rpg->all_objects->quest_obj[i].mushroom->rect, (sfVector2f) {1.1, 1.1});
}
