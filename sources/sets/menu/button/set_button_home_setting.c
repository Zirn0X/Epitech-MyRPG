/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_button_home_setting
*/

#include <stdlib.h>
#include "my_rpg.h"

char *my_strcat(char *str1, char *str2);
void set_home_hitbox(interface_t *home);
void set_home_rect(interface_t *home, int width, int heigth, int i);

static void set_home_setting_rect_pos(interface_t *home_setting)
{
    sfRectangleShape_setPosition
    (home_setting->button[0]->button, (sfVector2f) {150, 75});
    sfRectangleShape_setPosition
    (home_setting->button[1]->button, (sfVector2f) {820, 75});
    sfRectangleShape_setPosition
    (home_setting->button[2]->button, (sfVector2f) {1450, 75});
    sfRectangleShape_setPosition
    (home_setting->button[3]->button, (sfVector2f) {150, 400});
    sfRectangleShape_setPosition
    (home_setting->button[4]->button, (sfVector2f) {150, 600});
    sfRectangleShape_setPosition
    (home_setting->button[5]->button, (sfVector2f) {820, 400});
    sfRectangleShape_setPosition
    (home_setting->button[6]->button, (sfVector2f) {820, 600});
    sfRectangleShape_setPosition
    (home_setting->button[7]->button, (sfVector2f) {820, 800});
}

static void set_rect_home_setting(interface_t *home_setting)
{
    set_home_rect(home_setting, 472, 164, 0);
    set_home_rect(home_setting, 789, 164, 1);
    set_home_rect(home_setting, 682, 164, 2);
    set_home_rect(home_setting, 283, 160, 3);
    set_home_rect(home_setting, 500, 500, 4);
    set_home_rect(home_setting, 409, 164, 5);
    set_home_rect(home_setting, 417, 164, 6);
    set_home_rect(home_setting, 453, 164, 7);
}

static void set_texture_button_home_setting(interface_t *home_setting, int nb)
{
    char *asset_name[] = {"sound.png", "framerate.png", "command.png",
                        "sound.png", "speaker.png", "frame30.png",
                        "frame60.png", "frame120.png"};

    set_rect_home_setting(home_setting);
    for (int i = 0; i != nb; i++) {
        home_setting->button[i]->texture =
        sfTexture_createFromFile(my_strcat("assets/", asset_name[i]) , NULL);
        sfRectangleShape_setTexture(home_setting->button[i]->button,
        home_setting->button[i]->texture, sfFalse);
        sfRectangleShape_setTextureRect(home_setting->button[i]->button,
        home_setting->button[i]->rect);
    }
}

void set_button_home_setting(interface_t *home_setting, int nb_rect)
{
    sfVector2f size = {300, 100};

    home_setting->nb_rect = nb_rect;
    for (int i = 0; i < home_setting->nb_rect; i++) {
        home_setting->button[i] = malloc(sizeof(button_t));
        home_setting->button[i]->button = sfRectangleShape_create();
    }
    set_texture_button_home_setting(home_setting, nb_rect);
    for (int i = 0; i != home_setting->nb_rect; i++) {
        sfRectangleShape_setSize
        (home_setting->button[i]->button, size);
    }
    sfRectangleShape_setSize
        (home_setting->button[4]->button, (sfVector2f){200, 200});
    set_home_setting_rect_pos(home_setting);
    set_home_hitbox(home_setting);
}
