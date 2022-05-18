/*
** EPITECH PROJECT, 2022
** display_monsters.c
** File description:
** display_monster
*/

#include "my_rpg.h"
#include "my_macro.h"

void enemy_action_animated(my_rpg_t *rpg, my_sprite_t *sprite,
    void (*function));
void monsters_deplacement(my_rpg_t *rpg, my_sprite_t *ennemy);
void action_enemy_attack(my_rpg_t *rpg, my_sprite_t *sprite);

void display_monster(my_rpg_t *rpg, monster_type_t *monster, int nb_monsters)
{
    for (int i = 0; i != nb_monsters; ++i) {
        if (monster->monster[i].activate == true) {
            action_enemy_attack(rpg, &monster->monster[i]);
            enemy_action_animated(rpg, &monster->monster[i],
            &(monsters_deplacement));
            if (rpg->player->objects[0].used == true) {
                sfRenderWindow_drawSprite(rpg->manager->window,
                monster->monster[i].sprite, NULL);
                sfRenderWindow_drawRectangleShape(rpg->manager->window,
                monster->monster[i].bar_life, NULL);
            }
        }
    }
}