/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** use_bandage
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "objects/object_utils.h"
#include "player/player_competencies.h"

int is_inventory_key(my_rpg_t *rpg, int key);

void use_bandage(my_rpg_t *rpg, sfEventType event, int key, int idx)
{
    if (event == sfEvtKeyPressed && is_inventory_key(rpg, key) == SUCCESS) {
        add_point_health(rpg->player->compentencies, 50);
        rpg->player->inventory->rectangle[idx].obj->quantity -= 1;
    }
    if (rpg->player->inventory->rectangle[idx].obj->quantity <= 0)
        delete_from_inventory(rpg, idx);
}
