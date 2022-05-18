/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_potions
*/

#include "my_rpg.h"
#include "my_lib.h"

void set_health_potion(my_rpg_t *rpg)
{
    rpg->all_objects->health_potion =
    create_object("health_potion", 1, 100, 1);
    rpg->all_objects->health_potion->flag = 'H';
}

void set_defense_potion(my_rpg_t *rpg)
{
    rpg->all_objects->defense_potion =
    create_object("defense_potion", 1, 100, 1);
    rpg->all_objects->defense_potion->flag = 'D';
}

void set_attack_potion(my_rpg_t *rpg)
{
    rpg->all_objects->attack_potion =
    create_object("attack_potion", 1, 100, 1);
    rpg->all_objects->attack_potion->flag = 'A';
}

void set_speed_potion(my_rpg_t *rpg)
{
    rpg->all_objects->speed_potion =
    create_object("speed_potion", 1, 100, 1);
    rpg->all_objects->speed_potion->flag = 'S';

}
