/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** utils_object
*/

#include "my_rpg.h"
#include "my_macro.h"

void delete_from_inventory(my_rpg_t *rpg, int idx)
{
    rpg->player->inventory->rectangle[idx].obj->name = NULL;
    rpg->player->inventory->rectangle[idx].obj->damage = 0;
    rpg->player->inventory->rectangle[idx].obj->durability = 0;
    rpg->player->inventory->rectangle[idx].obj->flag = ' ';
    rpg->player->inventory->rectangle[idx].texture =
    sfTexture_createFromFile("assets/object/nothing.png", NULL);
    sfRectangleShape_setTexture
    (rpg->player->inventory->rectangle[idx].rect_shape,
    rpg->player->inventory->rectangle[idx].texture, sfFalse);
    rpg->player->inventory->rectangle[idx].obj->quantity = 0;
}

void add_to_inventory(my_rpg_t *rpg, objects_t *obj, char *file, int idx)
{
    int full = 0;

    for (int i = 0; i < NB_PLAYER_OBJECTS; i++, full++) {
        if (rpg->player->inventory->rectangle[i].obj->flag == obj->flag) {
            idx = i;
            break;
        } else if (rpg->player->inventory->rectangle[i].obj->flag == ' ') {
            idx = i;
            break;
        }
    }
    if (full == NB_PLAYER_OBJECTS)
        return;
    rpg->player->inventory->rectangle[idx].texture =
    sfTexture_createFromFile(file, NULL);
    sfRectangleShape_setTexture
    (rpg->player->inventory->rectangle[idx].rect_shape,
    rpg->player->inventory->rectangle[idx].texture, sfFalse);
    rpg->player->inventory->rectangle[idx].obj->flag = obj->flag;
    rpg->player->inventory->rectangle[idx].obj->quantity += 1;
}

void init_object(objects_t *object)
{
    object->name = NULL;
    object->flag = ' ';
    object->damage = 0;
    object->quantity = 0;
    object->durability = 0;
}
