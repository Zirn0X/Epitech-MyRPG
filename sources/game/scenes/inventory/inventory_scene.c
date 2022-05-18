/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** inventory_scene
*/

#include "my_rpg.h"
#include "my_macro.h"

void set_rectangle_pos(my_rpg_t *rpg, int add_x, int add_y, int idx);

static void draw_inventory_bar_obj(my_rpg_t *rpg)
{
    set_rectangle_pos(rpg, -165, 360, 0);
    set_rectangle_pos(rpg, -105, 360, 1);
    set_rectangle_pos(rpg, -45, 360, 2);
    set_rectangle_pos(rpg, 15, 360, 3);
    set_rectangle_pos(rpg, 75, 360, 4);
    set_rectangle_pos(rpg, 135, 360, 5);
    set_rectangle_pos(rpg, 195, 360, 6);
    for (int i = 0; i < NB_PLAYER_OBJECTS; i++)
        sfRenderWindow_drawRectangleShape(rpg->manager->window,
        rpg->player->inventory->rectangle[i].rect_shape, sfFalse);
}

void draw_inventory_bar(my_rpg_t *rpg)
{
    sfSprite_setPosition(rpg->player->inventory->sprite[0].sprite,
    (sfVector2f) {rpg->player->sprite->position.x - 170, rpg->player->sprite->position.y + 350});
    sfRenderWindow_drawSprite(rpg->manager->window,
    rpg->player->inventory->sprite[0].sprite, sfFalse);
    draw_inventory_bar_obj(rpg);
}
