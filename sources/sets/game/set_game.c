/*
** EPITECH PROJECT, 2022
** set_game.c
** File description:
** set_game
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"

static void set_zone_house_rect(my_rectshape_t *rect)
{
    rect->rect_shape = sfRectangleShape_create();
    rect->position = (sfVector2f) {1370, 1960};
    sfRectangleShape_setFillColor(rect->rect_shape, sfRed);
    sfRectangleShape_setSize(rect->rect_shape, (sfVector2f) {80, 30});
    sfRectangleShape_setPosition(rect->rect_shape, rect->position);
}

static void set_zone_ext_rect(my_rectshape_t *rect)
{
    rect->rect_shape = sfRectangleShape_create();
    rect->position = (sfVector2f) {9915, 291};
    sfRectangleShape_setFillColor(rect->rect_shape, sfRed);
    sfRectangleShape_setSize(rect->rect_shape, (sfVector2f) {80, 30 });
    sfRectangleShape_setPosition(rect->rect_shape, rect->position);
}

int set_game(my_rpg_t *rpg)
{
    rpg->game->zone_h_leave = malloc(sizeof(my_rectshape_t));
    rpg->game->zone_ext_leave = malloc(sizeof(my_rectshape_t));

    if (rpg->game->zone_h_leave == NULL)
        return (ERROR);
    set_zone_house_rect(rpg->game->zone_h_leave);
    set_zone_ext_rect(rpg->game->zone_ext_leave);
    rpg->game->scenes = 0;
    rpg->game->quests = 0;
    rpg->game->is_in_dialog = 0;
    rpg->game->current_dialog = 0;
    return (SUCCESS);
}