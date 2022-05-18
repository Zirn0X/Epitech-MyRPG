/*
** EPITECH PROJECT, 2022
** display_map.c
** File description:
** display_map
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "math.h"

int check_display_vision(my_rpg_t *rpg, map_t *map, int i, int j)
{
    sfVector2f pos_map = sfSprite_getPosition(map->map_sprite[i][j]);
    sfVector2f end;
    float rayon = 0;

    end.x = pos_map.x - rpg->player->sprite->position.x;
    end.y = pos_map.y - rpg->player->sprite->position.y;
    rayon = sqrt(end.x * end.x + end.y * end.y);
    if (rayon <= 1500.0)
        return (SUCCESS);
    return (ERROR);
}

static void display_layer(my_rpg_t *rpg, map_t *map)
{
    for (int i = 0; i < map->lines; i++) {
        for (int j = 0; j < map->cols; j++) {
            if (check_display_vision(rpg, map, i, j) == SUCCESS)
                sfRenderWindow_drawSprite(rpg->manager->window,
                map->map_sprite[i][j], sfFalse);
        }
    }
}

void display_map(my_rpg_t *rpg)
{
    for (int i = 0; i != rpg->maps->layer_map; ++i) {
        display_layer(rpg, &rpg->maps->maps[rpg->maps->map_use][i]);
    }
}