/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** utils_sound
*/

#include "my_rpg.h"
#include "my_macro.h"

void check_sound(my_rpg_t *rpg)
{
    // if (i == 3)
    //     return;
    if (rpg->manager->sound == UNMUTE) {
        rpg->home_setting->button[4]->rect.left = 0;
        sfRectangleShape_setTextureRect(rpg->home_setting->button[4]->button,
        rpg->home_setting->button[4]->rect);
        sfMusic_setVolume(rpg->home_menu->music, 50);
        return;
    }
    if (rpg->manager->sound == MUTE) {
        rpg->home_setting->button[4]->rect.left = 500;
        sfRectangleShape_setTextureRect(rpg->home_setting->button[4]->button,
        rpg->home_setting->button[4]->rect);
        sfMusic_setVolume(rpg->home_menu->music, 0);
        return;
    }
}

static void check_sound_case(my_rpg_t *rpg, int i)
{
    if (i == 3)
        return;
    if (i == 4 && rpg->manager->sound == UNMUTE) {
        rpg->manager->sound = MUTE;
        return;
    }
    if (i == 4 && rpg->manager->sound == MUTE) {
        rpg->manager->sound = UNMUTE;
        return;
    }
}

void sound_clicked(my_rpg_t *rpg, sfVector2f pos_click)
{
    for (int i = 3; i < 5; i++) {
        if (pos_click.x >= rpg->home_setting->button[i]->hit_min.x
        && pos_click.x <=  rpg->home_setting->button[i]->hit_max.x
        && pos_click.y >=  rpg->home_setting->button[i]->hit_min.y
        && pos_click.y <=  rpg->home_setting->button[i]->hit_max.y)
            check_sound_case(rpg, i);
    }
}
