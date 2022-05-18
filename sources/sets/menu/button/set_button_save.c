/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_button_save
*/

#include <stdlib.h>
#include "my_rpg.h"

char *my_strcat(char *str1, char *str2);
void set_home_hitbox(interface_t *home);
void set_home_rect(interface_t *home, int width, int heigth, int i);

static void set_save_rect_pos(interface_t *save)
{
    sfRectangleShape_setPosition
    (save->button[0]->button, (sfVector2f) {150, 100});
    sfRectangleShape_setPosition
    (save->button[1]->button, (sfVector2f) {820, 100});
    sfRectangleShape_setPosition
    (save->button[2]->button, (sfVector2f) {1450, 100});
    sfRectangleShape_setPosition
    (save->button[3]->button, (sfVector2f) {180, 300});
    sfRectangleShape_setPosition
    (save->button[4]->button, (sfVector2f) {850, 300});
    sfRectangleShape_setPosition
    (save->button[5]->button, (sfVector2f) {1480, 300});
    sfRectangleShape_setPosition
    (save->button[6]->button, (sfVector2f) {50, 900});
    sfRectangleShape_setPosition
    (save->button[7]->button, (sfVector2f) {820, 900});
    sfRectangleShape_setPosition
    (save->button[8]->button, (sfVector2f) {1500, 900});
}

static void set_rect_save(interface_t *save)
{
    set_home_rect(save, 415, 164, 0);
    set_home_rect(save, 451, 164, 1);
    set_home_rect(save, 442, 164, 2);
    set_home_rect(save, 250, 300, 3);
    set_home_rect(save, 250, 300, 4);
    set_home_rect(save, 250, 300, 5);
    set_home_rect(save, 336, 159, 6);
    set_home_rect(save, 402, 164, 7);
    set_home_rect(save, 432, 164, 8);
}

static void set_texture_button_save(interface_t *save, int nb)
{
    char *asset_name[] = {"save1.png", "save2.png", "save3.png",
                        "hero_save.png", "hero_save2.png", "hero_save3.png",
                        "back.png", "start.png", "delete.png"};
    set_rect_save(save);
    for (int i = 0; i != nb; i++) {
        save->button[i]->texture =
        sfTexture_createFromFile(my_strcat("assets/", asset_name[i]) , NULL);
        sfRectangleShape_setTexture(save->button[i]->button,
        save->button[i]->texture, sfFalse);
        sfRectangleShape_setTextureRect(save->button[i]->button,
        save->button[i]->rect);
    }
}

void set_button_save(interface_t *save, int nb_rect)
{
    sfVector2f size = {300, 100};

    save->nb_rect = nb_rect;
    for (int i = 0; i < save->nb_rect; i++) {
        save->button[i] = malloc(sizeof(button_t));
        save->button[i]->button = sfRectangleShape_create();
    }
    set_texture_button_save(save, nb_rect);
    for (int i = 0; i != save->nb_rect; i++) {
        if (i >= 3 && i <= 5)
            size = (sfVector2f) {250, 300};
        else
            size = (sfVector2f) {300, 100};
        sfRectangleShape_setSize
        (save->button[i]->button, size);
    }
    set_save_rect_pos(save);
    set_home_hitbox(save);
}
