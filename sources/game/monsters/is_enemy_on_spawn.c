/*
** EPITECH PROJECT, 2022
** enemy_to_spawner.c
** File description:
** enemy_to_spawner
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void bar_life_follow(my_rpg_t *rpg, my_sprite_t *sprite, sfVector2f position);

void enemy_to_his_spawner(my_rpg_t *rpg, my_sprite_t *sprite, float offset)
{
    if (sprite->position.x < sprite->spawner.x)
        sprite->position.x += offset;
    if (sprite->position.x > sprite->spawner.x)
        sprite->position.x -= offset;
    if (sprite->position.y < sprite->spawner.y)
        sprite->position.y += offset;
    if (sprite->position.y > sprite->spawner.y)
        sprite->position.y -= offset;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    bar_life_follow(rpg, sprite, (sfVector2f)
    {sprite->position.x - 20, sprite->position.y - 20});
}

int is_enemy_on_spawn(my_rpg_t *rpg, my_sprite_t *sprite, int width_max)
{
    float point[] = {sprite->position.x, sprite->position.y};

    if (sprite->position.x != sprite->spawner.x &&
    sprite->position.y != sprite->spawner.y) {
        sprite->action->seconds = sprite->action->seconds +
        sprite->action->acceleration * rpg->manager->dt->time;
        sprite->action->scd_animation = sprite->action->scd_animation +
        sprite->action->acceleration * rpg->manager->dt->time;
        if (sprite->action->seconds >= sprite->action->speed_max)
            sprite->action->seconds = sprite->action->speed_max;
        if (sprite->action->scd_animation >= sprite->action->speed_max_anim) {
            move_rect(&sprite->rect, 150, width_max, 0);
            sfSprite_setTextureRect(sprite->sprite, sprite->rect);
            sprite->action->scd_animation = 0;
        }
        enemy_to_his_spawner(rpg, sprite, sprite->action->seconds);
        if (is_point_in_circle(point, sprite->spawner.y, sprite->spawner.x, 10)
        == true)
            sprite->position = sprite->spawner;
        if (rpg->player->objects[0].used == true) {
            sfRenderWindow_drawRectangleShape(rpg->manager->window,
            sprite->bar_life, NULL);
            sfRenderWindow_drawSprite(rpg->manager->window,
            sprite->sprite, NULL);
        }
        return (ERROR);
    }
    sprite->action->seconds = 0;
    sprite->action->scd_animation = 0;
    return (SUCCESS);
}
