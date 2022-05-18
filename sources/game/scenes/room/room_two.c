/*
** EPITECH PROJECT, 2022
** room_two.c
** File description:
** room_two
*/

#include "my_rpg.h"
#include "my_macro.h"

void display_monsters_bf_ef(my_rpg_t *rpg, monster_type_t *monster);

void display_before_effects(my_rpg_t *rpg)
{
    if (rpg->player->objects[0].used == false) {
        sfRenderWindow_drawSprite(rpg->manager->window, rpg->player->sprite->
        sprite, NULL);
        display_monsters_bf_ef(rpg, &rpg->monsters->monsters[M_FLYING_EYE]);
        display_monsters_bf_ef(rpg, &rpg->monsters->monsters[M_THIEF]);
        display_monsters_bf_ef(rpg, &rpg->monsters->monsters[M_SKELETON]);
        display_monsters_bf_ef(rpg, &rpg->monsters->monsters[M_CYCLOPE]);
    }
}

void life_bar_follow_hud(my_rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->player->sprite->bar_life,
    (sfVector2f) {rpg->player->sprite->position.x - 720, rpg->player->sprite->
    position.y - 400});
}