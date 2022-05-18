/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** pause_scene
*/

#include "my_rpg.h"
#include "game/game_events.h"

void set_string_pos(my_rpg_t *rpg);
void set_pos_texture(my_rpg_t *rpg);

int pause_scene(my_rpg_t *rpg)
{
    set_string_pos(rpg);
    set_pos_texture(rpg);
    for (int i = 0; i != 4; i++)
        sfRenderWindow_drawText(rpg->manager->window, rpg->pause->name[i].text,
        sfFalse);
    sfRenderWindow_drawSprite(rpg->manager->window, rpg->pause->sprite_cursor,
    sfFalse);
    pause_events(rpg);
}
