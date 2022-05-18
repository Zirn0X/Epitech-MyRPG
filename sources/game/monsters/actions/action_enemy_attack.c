/*
** EPITECH PROJECT, 2022
** action_enemy_attack.c
** File description:
** action_enemy_attack
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void player_get_attacked(my_rpg_t *rpg, my_sprite_t *sprite)
{
    float damage = sprite->damage - (float)(rpg->player->compentencies->
    resistance);

    sprite->scd_attack = sprite->scd_attack +
    sprite->speed_sdc_attack * rpg->manager->dt->time;
    if (sprite->scd_attack >= sprite->sdc_attack_max) {
        rpg->player->sprite->life -= damage;
        if (rpg->player->sprite->life <= 0)
            rpg->player->sprite->life = 500;
        sfRectangleShape_setSize(rpg->player->sprite->bar_life,
        (sfVector2f) {rpg->player->sprite->life, 50});
        sprite->scd_attack = 0;
    }
}

void action_enemy_attack(my_rpg_t *rpg, my_sprite_t *sprite)
{
    float pos[] = {rpg->player->sprite->position.x, rpg->player->sprite
    ->position.y};

    if (is_point_in_circle(pos, sprite->position.y, sprite->position.x, 30)
    == true)
        player_get_attacked(rpg, sprite);
}
