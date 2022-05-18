/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** save_page_event
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void get_case_save(my_rpg_t *rpg, int i);
void hover_save(my_rpg_t *rpg, sfVector2f pos_mouse, int i);
void get_case_save(my_rpg_t *rpg, int i);
void get_name_hero(my_rpg_t *rpg, int idx);

void save_button_clicked(my_rpg_t *rpg, sfVector2f pos_click)
{
    int cond1 = 0;
    int cond2 = 0;
    int cond3 = 0;
    int cond4 = 0;

    for (int i = 0; i < rpg->home_save->nb_rect; i++) {
        cond1 = pos_click.x >= rpg->home_save->button[i]->hit_min.x;
        cond2 = pos_click.x <=  rpg->home_save->button[i]->hit_max.x;
        cond3 = pos_click.y >=  rpg->home_save->button[i]->hit_min.y;
        cond4 = pos_click.y <=  rpg->home_save->button[i]->hit_max.y;
        if (cond1 && cond2 && cond3 && cond4)
            get_case_save(rpg, i);
    }
}

void name_button_clicked(my_rpg_t *rpg, sfVector2f pos_click)
{
    int cond1 = 0;
    int cond2 = 0;
    int cond3 = 0;
    int cond4 = 0;

    for (int i = 0; i < 3; i++) {
        cond1 = pos_click.x >= rpg->home_save->name[i].pos.x;
        cond2 = pos_click.x <=  rpg->home_save->name[i].pos.x + 220;
        cond3 = pos_click.y >=  rpg->home_save->name[i].pos.y;
        cond4 = pos_click.y <=  rpg->home_save->name[i].pos.y + 220;
        if (cond1 && cond2 && cond3 && cond4)
            rpg->home_save->selected = i;
    }
}

void save_page_event(my_rpg_t *rpg)
{
    sfVector2f click_pos;

    for (int i = 6; i < rpg->home_save->nb_rect; i++) {
        hover_save(rpg, rpg->home_menu->pos_mouse, i);
        sfRectangleShape_setTextureRect(rpg->home_save->button[i]->button,
        rpg->home_save->button[i]->rect);
    }
    if (rpg->manager->event.type == sfEvtMouseButtonPressed) {
        click_pos = rpg->home_menu->pos_mouse;
        save_button_clicked(rpg, click_pos);
        name_button_clicked(rpg, click_pos);
    }
    if (rpg->home_save->selected != -1)
        get_name_hero(rpg, rpg->home_save->selected);
}
