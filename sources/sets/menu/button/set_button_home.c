/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_button
*/

#include <stdlib.h>
#include "my_rpg.h"

void set_home_hitbox(interface_t *home);

static void set_home_rect_pos(interface_t *home)
{
    sfRectangleShape_setPosition
    (home->button[0]->button, (sfVector2f) {700, 75});
    sfRectangleShape_setPosition
    (home->button[1]->button, (sfVector2f) {100, 400});
    sfRectangleShape_setPosition
    (home->button[2]->button, (sfVector2f) {100, 600});
    sfRectangleShape_setPosition
    (home->button[3]->button, (sfVector2f) {100, 800});
}

void set_home_rect(interface_t *home, int width, int heigth, int i)
{
    home->button[i]->rect.top = 0;
    home->button[i]->rect.left = 0;
    home->button[i]->rect.width = width;
    home->button[i]->rect.height = heigth;
}

static void set_texture_button_home(interface_t *home)
{
    home->button[0]->texture =
    sfTexture_createFromFile("assets/title.png", NULL);
    home->button[1]->texture =
    sfTexture_createFromFile("assets/play.png", NULL);
    home->button[2]->texture =
    sfTexture_createFromFile("assets/setting.png", NULL);
    home->button[3]->texture =
    sfTexture_createFromFile("assets/quit.png", NULL);
    sfRectangleShape_setTexture
    (home->button[0]->button, home->button[0]->texture, sfFalse);
    set_home_rect(home, 339, 162, 1);
    set_home_rect(home, 569, 164, 2);
    set_home_rect(home, 283, 160, 3);
    for (int i = 1; i < home->nb_rect; i++) {
        sfRectangleShape_setTexture
        (home->button[i]->button, home->button[i]->texture, sfFalse);
        sfRectangleShape_setTextureRect
        (home->button[i]->button, home->button[i]->rect);
    }
}

void set_button_home_menu(interface_t *home, int nb_rect)
{
    sfVector2f size = {500, 200};

    home->nb_rect = nb_rect;
    for (int i = 0; i < home->nb_rect; i++) {
        home->button[i] = malloc(sizeof(button_t));
        home->button[i]->button = sfRectangleShape_create();
    }
    set_texture_button_home(home);
    sfRectangleShape_setSize(home->button[0]->button, size);
    for (int i = 1; i != home->nb_rect; i++) {
        size = (sfVector2f) {300, 100};
        sfRectangleShape_setSize
        (home->button[i]->button, size);
    }
    set_home_rect_pos(home);
    set_home_hitbox(home);
}
