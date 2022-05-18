/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_hitbox
*/

#include "my_rpg.h"

static sfVector2f get_max_pos(sfVector2f pos, sfVector2f size)
{
    sfVector2f max_pos = {0, 0};

    max_pos.x = (pos.x + size.x);
    max_pos.y = pos.y + size.y;
    return (max_pos);
}

void set_home_hitbox(interface_t *home)
{
    sfVector2f max_pos;

    for (int i = 0; i < home->nb_rect; i++) {
        home->button[i]->hit_min =
        sfRectangleShape_getPosition(home->button[i]->button);
        max_pos = get_max_pos(sfRectangleShape_getPosition
        (home->button[i]->button),
        sfRectangleShape_getSize(home->button[i]->button));
        home->button[i]->hit_max = max_pos;
    }
}
