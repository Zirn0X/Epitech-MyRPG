/*
** EPITECH PROJECT, 2022
** player_inventory_events.c
** File description:
** player_inventory_events
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "player/player_competencies.h"

int is_inventory_key(my_rpg_t *rpg, int key)
{
    for (int i = KEY_INVENTORY_1; i != KEY_INVENTORY_7 + 1; ++i)
        if (key == i)
            return (SUCCESS);
    return (ERROR);
}

void use_lantern(my_rpg_t *rpg, sfEventType event, int key, int idx)
{
    if (event == sfEvtKeyPressed && is_inventory_key(rpg, key) == SUCCESS) {
        if (rpg->player->objects[(NB_INVENTORY + KEY_DIFF_THAN_INV) - key].used
        == sfFalse) {
            rpg->player->objects[(NB_INVENTORY + KEY_DIFF_THAN_INV)- key].used
            = sfTrue;
            rpg->manager->display_zone = 775.0;
            rpg->effects->darkest = 160;
            sfSprite_setColor(rpg->effects->shadow->sprite, (sfColor) {0, 0, 0,
            rpg->effects->darkest});
        } else {
            rpg->player->objects[(NB_INVENTORY + KEY_DIFF_THAN_INV) - key].used
            = sfFalse;
            rpg->manager->display_zone = 700.0;
            rpg->effects->darkest = 225;
            sfSprite_setColor(rpg->effects->shadow->sprite, (sfColor) {0, 0, 0,
            rpg->effects->darkest});
        }
    }
}

void player_inventory_events(my_rpg_t *rpg, sfEventType event, int key)
{
    typedef struct objects_table_s {
        char flag;
        void(*function)(my_rpg_t *rpg, sfEventType event, int key, int idx);
    } object_table_t;

    if (rpg->scenes->sub_scenes != 0)
        return;
    object_table_t obj[] = {
        {'L', &(use_lantern)}, {'H', &(use_health_potion)},
        {'D', &(use_defense_potion)}, {'A', &(use_attack_potion)},
        {'S', &(use_speed_potion)}, {'B', &(use_bandage)}
    };
    if (key < KEY_INVENTORY_1 || key > KEY_INVENTORY_7)
        return;
    for (unsigned long int i = 0; i < sizeof(obj) / sizeof(object_table_t);
    i++) {
        if (obj[i].flag ==
        rpg->player->inventory->rectangle[key - KEY_INVENTORY_1].obj->flag)
            obj[i].function(rpg, event, key, key - KEY_INVENTORY_1);
    }
}
