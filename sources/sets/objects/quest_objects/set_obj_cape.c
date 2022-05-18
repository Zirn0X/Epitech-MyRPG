/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_obj_cape
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void set_pos_obj_cape(all_objects_t *all_objects)
{
    all_objects->quest_obj[0].cape->pos = (sfVector2f) {5447, 4330};
    all_objects->quest_obj[1].cape->pos = (sfVector2f) {5446, 2755};
    all_objects->quest_obj[2].cape->pos = (sfVector2f) {6140, 3222};
    all_objects->quest_obj[3].cape->pos = (sfVector2f) {5174, 3466};
    all_objects->quest_obj[4].cape->pos = (sfVector2f) {6136, 4096};
    for (int i = 0; i != NB_CAPE; i++)
        sfRectangleShape_setPosition(all_objects->quest_obj[i].cape->rect,
        all_objects->quest_obj[i].cape->pos);
}

void initialize_obj_cape(my_rpg_t *rpg, int i)
{
    rpg->all_objects->quest_obj[i].nb_cape_get = 0;
    rpg->all_objects->quest_obj[i].cape = create_object("cape", 1, 100, 1);
    rpg->all_objects->quest_obj[i].cape->flag = 'C';
    rpg->all_objects->quest_obj[i].cape->rect = sfRectangleShape_create();
    rpg->all_objects->quest_obj[i].cape->texture =
    sfTexture_createFromFile("assets/object/obj_cape.png", NULL);
    sfRectangleShape_setSize(rpg->all_objects->quest_obj[i].cape->rect,
    (sfVector2f) {50, 50});
    sfRectangleShape_setTexture(rpg->all_objects->quest_obj[i].cape->rect,
    rpg->all_objects->quest_obj[i].cape->texture, sfFalse);
    sfRectangleShape_setScale
    (rpg->all_objects->quest_obj[i].cape->rect, (sfVector2f) {1.1, 1.1});
}
