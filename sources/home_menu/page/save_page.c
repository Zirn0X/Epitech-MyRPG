/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** save_page
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void display_cursor(sfRenderWindow *window, interface_t *home);
void set_button_save(interface_t *save, int nb_rect);
char *my_itoa(int nb);

void get_name_save(interface_t *save, int i)
{
    char *path = malloc(sizeof(char) * 20);
    int lines = 0;
    char *buffer = NULL;
    char **tab = NULL;

    path = my_strcat("config_file/.save", my_itoa(i + 1));
    buffer = read_file_wo_stat(path, &lines);
    tab = my_str_to_word_array(buffer, ':');
    if (my_strcmp(tab[1], "****") == 0)
        save->name[i].string = "Enter name:";
    else {
        save->name[i].string = tab[1];
        save->name[i].changable = NOT_CHANGABLE;
    }
    free(path);
}

void set_name_save(interface_t *save, int nb)
{
    save->selected = -1;
    save->name[0].pos = (sfVector2f) {175, 650};
    save->name[1].pos = (sfVector2f) {850, 650};
    save->name[2].pos = (sfVector2f) {1500, 650};
    for (int i = 0; i != nb; i++) {
        save->name[i].changable = CHANGABLE;
        get_name_save(save, i);
        save->name[i].text = sfText_create();
        save->name[i].font = sfFont_createFromFile("assets/first_job.ttf");
        sfText_setCharacterSize(save->name[i].text, 50);
        sfText_setPosition(save->name[i].text, save->name[i].pos);
        sfText_setColor(save->name[i].text, sfWhite);
        sfText_setFont(save->name[i].text, save->name[i].font);
        sfText_setString(save->name[i].text, save->name[i].string);
        sfText_setOutlineColor(save->name[i].text, sfRed);
        sfText_setOutlineThickness(save->name[i].text, 3);
    }
}

int set_home_save(my_rpg_t *rpg)
{
    rpg->home_save->pos_mouse.x = 0;
    rpg->home_save->pos_mouse.y = 0;
    rpg->home_save->nb_rect = 0;
    rpg->home_save->button = malloc(sizeof(button_t) * 9);
    rpg->home_save->name = malloc(sizeof(text_t) * 3);
    set_button_save(rpg->home_save, 9);
    set_name_save(rpg->home_save, 3);
    return (SUCCESS);
}

int save_page(my_rpg_t *rpg)
{
    for (int i = 0; i < rpg->home_save->nb_rect; i++)
        sfRenderWindow_drawRectangleShape(rpg->manager->window,
        rpg->home_save->button[i]->button, NULL);
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawText(rpg->manager->window,
        rpg->home_save->name[i].text, NULL);
    display_cursor(rpg->manager->window, rpg->home_menu);
    return (SUCCESS);
}
