/*
** EPITECH PROJECT, 2022
** home_page_event.c
** File description:
** home_page_event
*/

#include "my_rpg.h"
#include "my_macro.h"

void hover_home(my_rpg_t *rpg, sfVector2f pos_mouse, int i)
{
    if (pos_mouse.x >= rpg->home_menu->button[i]->hit_min.x
    && pos_mouse.x <= rpg->home_menu->button[i]->hit_max.x
    && pos_mouse.y >= rpg->home_menu->button[i]->hit_min.y
    && pos_mouse.y <= rpg->home_menu->button[i]->hit_max.y)
        rpg->home_menu->button[i]->rect.left =
        rpg->home_menu->button[i]->rect.width;
    else
        rpg->home_menu->button[i]->rect.left = 0;
    sfRectangleShape_setTextureRect(rpg->home_menu->button[i]->button,
    rpg->home_menu->button[i]->rect);
}

static void get_case_home(my_rpg_t *rpg, int i)
{
    if (i == 1)
        rpg->scenes->sub_scenes = SAVE_PAGE;
    if (i == 2)
        rpg->scenes->sub_scenes = SETTING_PAGE;
    if (i == 3)
        rpg->manager->end = QUIT;
}

void button_clicked(my_rpg_t *rpg, sfVector2f pos_click)
{
    for (int i = 0; i < rpg->home_menu->nb_rect; i++)
        if (pos_click.x >= rpg->home_menu->button[i]->hit_min.x
        && pos_click.x <=  rpg->home_menu->button[i]->hit_max.x
        && pos_click.y >=  rpg->home_menu->button[i]->hit_min.y
        && pos_click.y <=  rpg->home_menu->button[i]->hit_max.y)
            get_case_home(rpg, i);
}

void home_page_event(my_rpg_t *rpg)
{
    sfVector2f click_pos;

    for (int i = 1; i < rpg->home_menu->nb_rect; i++)
        hover_home(rpg, rpg->home_menu->pos_mouse, i);
    if (rpg->manager->event.type == sfEvtMouseButtonPressed) {
        click_pos = rpg->home_menu->pos_mouse;
        button_clicked(rpg, click_pos);
    }
}
