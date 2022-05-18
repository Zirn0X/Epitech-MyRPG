/*
** EPITECH PROJECT, 2022
** atatck_enemies.c
** File description:
** attack_enemies
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void enemy_attacked(my_rpg_t *rpg, my_sprite_t *sprite)
{
    float damage_add = rpg->player->sprite->damage *
        (((float)rpg->player->compentencies->attack * 100.0) / 100.0);

    sprite->life -= damage_add;
    if (sprite->life <= 0) {
        sprite->life = 100;
        sprite->activate = false;
        sfRectangleShape_setSize(sprite->bar_life, (sfVector2f) {100, 10});
        sfSprite_setPosition(sprite->sprite, sprite->spawner);
    } else
        sfRectangleShape_setSize(sprite->bar_life, (sfVector2f) {sprite->life, 10});
}

void attack_thief(my_rpg_t *rpg, int type_monster)
{
    float pos[] = {0, 0};

    for (int i = 0; i != M_THIEF_NB; ++i) {
        pos[0] = rpg->monsters->monsters[type_monster].monster[i].position.x;
        pos[1] = rpg->monsters->monsters[type_monster].monster[i].position.y;
        if (is_point_in_circle(pos, rpg->player->sprite->position.y,rpg->player
        ->sprite->position.x, 30) == true) {
            enemy_attacked(rpg, &rpg->monsters->monsters[type_monster].monster[i]);
        }
    }
}

void attack_enemies(my_rpg_t *rpg)
{
    attack_thief(rpg, M_FLYING_EYE);
    attack_thief(rpg, M_THIEF);
    attack_thief(rpg, M_SKELETON);
    attack_thief(rpg, M_CYCLOPE);
}