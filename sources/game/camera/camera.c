/*
** EPITECH PROJECT, 2022
** camera.c
** File description:
** camera
*/

#include "my_rpg.h"
#include "my_macro.h"

void display_effects(my_rpg_t *rpg);
void effects_following(my_rpg_t *rpg, my_sprite_t *effect, float len_x,
float len_y);

void camera_follow_player(my_rpg_t *rpg)
{
    sfView_setCenter(rpg->manager->camera, (sfVector2f)
    {rpg->player->sprite->position.x + (PLAYER_WIDTH / 2),
    rpg->player->sprite->position.y + (PLAYER_WIDTH / 2)});
    sfRenderWindow_setView(rpg->manager->window, rpg->manager->camera);
    effects_following(rpg, rpg->effects->shadow, LEN_SHADOW_X, LEN_SHADOW_Y);
    effects_following(rpg, rpg->effects->lanthern, LEN_LANTHERN_X,
    LEN_LANTHERN_Y);
    display_effects(rpg);
    return;
}