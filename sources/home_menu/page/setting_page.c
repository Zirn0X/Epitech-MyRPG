/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** setting_page
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"

void set_button_home_setting(interface_t *home_setting, int nb_rect);
void frame_clicked(my_rpg_t *rpg, sfVector2f pos_click);
void sound_clicked(my_rpg_t *rpg, sfVector2f pos_click);
void check_fps(my_rpg_t *rpg);
void check_sound(my_rpg_t *rpg);
void display_cursor(sfRenderWindow *window, interface_t *home);

void setting_home_event(my_rpg_t *rpg)
{
    sfVector2f click_pos;

    check_fps(rpg);
    check_sound(rpg);
    if (rpg->manager->event.type == sfEvtMouseButtonPressed) {
        click_pos = rpg->home_menu->pos_mouse;
        sound_clicked(rpg, click_pos);
        frame_clicked(rpg, click_pos);
    }
    if (rpg->manager->event.type == sfEvtKeyPressed
    && rpg->manager->event.key.code == sfKeyEscape)
        rpg->scenes->sub_scenes = HOME_PAGE;
}

int set_home_setting(my_rpg_t *rpg)
{
    rpg->home_setting->pos_mouse.x = 0;
    rpg->home_setting->pos_mouse.y = 0;
    rpg->home_setting->nb_rect = 0;
    rpg->home_setting->button = malloc(sizeof(button_t) * 8);
    set_button_home_setting(rpg->home_setting, 8);
    return (SUCCESS);
}

int setting_page(my_rpg_t *rpg)
{
    sfRenderWindow_drawSprite
    (rpg->manager->window, rpg->home_menu->sprite_back, NULL);
    for (int i = 0; i < rpg->home_setting->nb_rect; i++)
        sfRenderWindow_drawRectangleShape(rpg->manager->window,
        rpg->home_setting->button[i]->button, NULL);
    display_cursor(rpg->manager->window, rpg->home_menu);
    return (SUCCESS);
}
