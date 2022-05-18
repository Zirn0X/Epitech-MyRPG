/*
** EPITECH PROJECT, 2022
** desactive_spawner.c
** File description:
** desactive_spawner
*/

#include "my_rpg.h"
#include "my_macro.h"

void bar_life_follow(my_rpg_t *rpg, my_sprite_t *sprite, sfVector2f position);
int is_enemy_on_spawn(my_rpg_t *rpg, my_sprite_t *sprite, int width_max);

void desactive_spawner(my_rpg_t *rpg, int type_monsters, int type_spawn)
{
    for (int i = 0; i != rpg->monsters->monsters[type_monsters].nb_monster;
    ++i) {
        if (is_enemy_on_spawn(rpg, &rpg->monsters->monsters[type_monsters].
        monster[i], 750) == SUCCESS) {
            rpg->monsters->monsters[type_monsters].monster[i].activate = false;
            rpg->monsters->monsters[type_monsters].monster[i].action->seconds
            = 0;
        }
    }
    rpg->monsters->spawner[type_monsters].activate = false;
}