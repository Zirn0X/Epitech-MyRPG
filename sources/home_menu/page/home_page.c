/*
** EPITECH PROJECT, 2022
** home_menu.c
** File description:
** home_menu
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"

void display_cursor(sfRenderWindow *window, interface_t *home);
void set_button_home_menu(interface_t *home, int nb_rect);
void home_page_event(manager_t *manager, my_rpg_t *rpg);
void my_rpg_events(manager_t *manager, my_rpg_t *rpg);;

int set_home_menu(my_rpg_t *rpg)
{
    rpg->fps = 0;
    rpg->home_menu->pos_mouse.x = 0;
    rpg->home_menu->pos_mouse.y = 0;
    rpg->home_menu->nb_rect = 0;
    rpg->home_menu->button = malloc(sizeof(button_t) * 4);
    set_button_home_menu(rpg->home_menu, 4);
    rpg->home_menu->sprite_back = sfSprite_create();
    rpg->home_menu->texture_back =
    sfTexture_createFromFile("assets/haunted.jpg", NULL);
    sfSprite_setTexture
    (rpg->home_menu->sprite_back, rpg->home_menu->texture_back, sfFalse);
    rpg->home_menu->music = sfMusic_createFromFile("assets/home_music.ogg");
    sfMusic_play(rpg->home_menu->music);
    sfMusic_setVolume(rpg->home_menu->music, 10);
    sfMusic_setLoop(rpg->home_menu->music, sfTrue);
    return (SUCCESS);
}

int home_page(my_rpg_t *rpg)
{
    sfRenderWindow_drawSprite
    (rpg->manager->window, rpg->home_menu->sprite_back, NULL);
    for (int i = 0; i < rpg->home_menu->nb_rect; i++)
        sfRenderWindow_drawRectangleShape(rpg->manager->window,
        rpg->home_menu->button[i]->button, NULL);
    display_cursor(rpg->manager->window, rpg->home_menu);
    return (SUCCESS);
}
