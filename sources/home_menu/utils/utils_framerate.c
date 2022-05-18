/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** utils_framerate
*/

#include "my_rpg.h"
#include "my_macro.h"

void check_fps(my_rpg_t *rpg)
{
    if (rpg->fps == 0) {
        sfRenderWindow_setFramerateLimit(rpg->manager->window, 30);
        rpg->home_setting->button[5]->rect.left = 409;
        rpg->home_setting->button[6]->rect.left = 0;
        rpg->home_setting->button[7]->rect.left = 0;
    } else if (rpg->fps == 1) {
        sfRenderWindow_setFramerateLimit(rpg->manager->window, 60);
        rpg->home_setting->button[5]->rect.left = 0;
        rpg->home_setting->button[6]->rect.left = 417;
        rpg->home_setting->button[7]->rect.left = 0;
    } else {
        sfRenderWindow_setFramerateLimit(rpg->manager->window, 120);
        rpg->home_setting->button[5]->rect.left = 0;
        rpg->home_setting->button[6]->rect.left = 0;
        rpg->home_setting->button[7]->rect.left = 453;
    }
    for (int i = 5; i != 8; i++)
        sfRectangleShape_setTextureRect(rpg->home_setting->button[i]->button,
        rpg->home_setting->button[i]->rect);
}

static void check_case_frame(my_rpg_t *rpg, int i)
{
    if (i == 5)
        rpg->fps = FRAME30;
    if (i == 6)
        rpg->fps = FRAME60;
    if (i == 7)
        rpg->fps = FRAME120;
}

void frame_clicked(my_rpg_t *rpg, sfVector2f pos_click)
{
    for (int i = 5; i < rpg->home_setting->nb_rect; i++) {
        if (pos_click.x >= rpg->home_setting->button[i]->hit_min.x
        && pos_click.x <=  rpg->home_setting->button[i]->hit_max.x
        && pos_click.y >=  rpg->home_setting->button[i]->hit_min.y
        && pos_click.y <=  rpg->home_setting->button[i]->hit_max.y)
            check_case_frame(rpg, i);
    }
}
