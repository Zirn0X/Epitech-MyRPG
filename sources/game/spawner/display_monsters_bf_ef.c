/*
** EPITECH PROJECT, 2022
** display_monsters_bf_ef.c
** File description:
** displaye_monsters_bf_ef
*/

#include "my_rpg.h"
#include "my_macro.h"

void display_monsters_bf_ef(my_rpg_t *rpg, monster_type_t *monster)
{
    for (int i = 0; i != monster->nb_monster; ++i) {
        if (monster->monster[i].activate == true) {
            sfRenderWindow_drawSprite(rpg->manager->window, monster->monster[i]
            .sprite, NULL);
            sfRenderWindow_drawRectangleShape(rpg->manager->window,
            monster->monster[i].bar_life, NULL);
        }
    }
}