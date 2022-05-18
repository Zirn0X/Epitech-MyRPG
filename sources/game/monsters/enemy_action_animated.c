/*
** EPITECH PROJECT, 2022
** player_execture_action.c
** File description:
** player_execute_action
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void action_enemy_attack(my_rpg_t *rpg, my_sprite_t *sprite);

void enemy_spawn_at_time(my_rpg_t *rpg, int type_spawn, int scd_spawn_max)
{
    monster_type_t *monster = &rpg->monsters->monsters[type_spawn];
    int monster_index = 0;

    monster->scd_spawn = monster->scd_spawn +
    monster->sp_acce * rpg->manager->dt->time;
    if (monster->scd_spawn >= scd_spawn_max) {
        while (monster->monster[monster_index].activate == true &&
        monster_index != rpg->monsters->monsters[type_spawn].nb_monster)
            monster_index += 1;
        monster->monster[monster_index].activate = true;
        monster->scd_spawn = 0;
    }
}

void enemy_action_animated(my_rpg_t *rpg, my_sprite_t *sprite,
void (*function)(my_rpg_t *rpg, my_sprite_t *enemy, float offset))
{
    sprite->action->seconds = sprite->action->seconds +
    sprite->action->acceleration * rpg->manager->dt->time;
    sprite->action->scd_animation = sprite->action->scd_animation +
    sprite->action->acceleration * rpg->manager->dt->time;
    if (sprite->action->seconds >= sprite->action->speed_max)
        sprite->action->seconds = sprite->action->speed_max;
    if (sprite->action->scd_animation >= sprite->action->speed_max_anim) {
        move_rect(&sprite->rect, sprite->offset, sprite->off_set_max, 0);
        sfSprite_setTextureRect(sprite->sprite, sprite->rect);
        sprite->action->scd_animation = 0;
    }
    function(rpg, sprite, sprite->action->seconds);
    sprite->activate = true;
}
