/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Create map with sprites
*/

#include <stdlib.h>
#include "map/read_map.h"
#include "my_rpg.h"
#include "my_macro.h"

sfIntRect calc(int id, int largeur)
{
    sfIntRect rect = {0, 0, 0, 0};
    int y = -1;
    int x = 0;

    for (int nb_case = 0; nb_case != id; nb_case++, x++) {
        if ((nb_case % largeur) == 0) {
            y += 1;
            x = 0;
        }
    }
    if (id % largeur == 0) {
        x = 0;
        y += 1;
    }
    rect.top = y * TUILE_SIZE;
    rect.left = x * TUILE_SIZE;
    rect.width = TUILE_SIZE;
    rect.height = TUILE_SIZE;
    return rect;
}

void create_sprite_map(map_t *map_struct, int mult)
{
    sfSprite ***s_map = malloc(sizeof(sfSprite *) * (map_struct->lines + 1));
    sfTexture *t_map = sfTexture_createFromFile(map_struct->sprite_texture, NULL);
    sfIntRect rect = {0, 0, 16, 16};
    float x = 0;
    float y = 0;

    map_struct->x = malloc(sizeof(float *) * (map_struct->lines + 1));
    map_struct->y = malloc(sizeof(float *) * (map_struct->lines + 1));
    for (int i = 0; i < map_struct->lines; i++) {
        s_map[i] = malloc(sizeof(sfSprite *) * (map_struct->cols + 1));
        map_struct->x[i] = malloc(sizeof(float) * (map_struct->cols + 1));
        map_struct->y[i] = malloc(sizeof(float) * (map_struct->cols + 1));

        for (int j = 0; j < map_struct->cols; j++) {
            s_map[i][j] = sfSprite_create();
            if (map_struct->int_map_array[i][j] == -1) {
                sfSprite_setPosition(s_map[i][j], (sfVector2f) {x, y});
                if (mult == 1)
                    x += TUILE_SIZE * MULTIPLICATOR_SIZE;
                else
                    x += TUILE_SIZE;
                continue;
            }
            sfSprite_setTexture(s_map[i][j], t_map, sfFalse);
            rect = calc(map_struct->int_map_array[i][j], map_struct->width / 32);
            sfSprite_setTextureRect(s_map[i][j], rect);
            if (mult == 1)
                sfSprite_setScale(s_map[i][j], (sfVector2f) {2.5, 2.5});
            sfSprite_setPosition(s_map[i][j], (sfVector2f) {x, y});
            map_struct->x[i][j] = x;
            map_struct->y[i][j] = y;
            if (mult== 1)
                x += TUILE_SIZE * MULTIPLICATOR_SIZE;
            else
                x += TUILE_SIZE;
        }
        x = 0;
        if (mult == 1)
            y += TUILE_SIZE * MULTIPLICATOR_SIZE;
        else
            y += TUILE_SIZE;

    }
    map_struct->map_sprite = s_map;
}
