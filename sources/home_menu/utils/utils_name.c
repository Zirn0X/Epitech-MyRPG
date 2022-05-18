/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** utils_name
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_lib.h"
#include "my_macro.h"

static void write_name(my_rpg_t *rpg, sfUint32 c, int idx, int i)
{
    c = rpg->manager->event.text.unicode;
    c = (char){c};
    rpg->home_save->name[idx].string[i] = c;
    rpg->home_save->name[idx].string[i + 1] = '\0';
    sfText_setString(rpg->home_save->name[idx].text,
    rpg->home_save->name[idx].string);
}

static void delete_char(my_rpg_t *rpg, int idx, int i)
{
    if (my_strlen(rpg->home_save->name[idx].string) == 0)
        return;
    rpg->home_save->name[idx].string[i - 1] = '\0';
    sfText_setString(rpg->home_save->name[idx].text,
        rpg->home_save->name[idx].string);
}

static void enter_name(my_rpg_t *rpg, int idx)
{
    int len = my_strlen(rpg->home_save->name[idx].string);

    rpg->home_save->name[idx].changable = 1;
    rpg->player->name = malloc(sizeof(char) * len + 1);
    rpg->player->name = rpg->home_save->name[idx].string;
}

void get_name_hero(my_rpg_t *rpg, int idx)
{
    sfUint32 c;
    int i = 0;

    if (rpg->home_save->name[idx].changable == 1)
        return;
    if (my_strcmp(rpg->home_save->name[idx].string, "Enter name:") == 0) {
        rpg->home_save->name[idx].string = malloc(sizeof(char) * 26);
        rpg->home_save->name[idx].string[0] = '\0';
    }
    i = my_strlen(rpg->home_save->name[idx].string);
    if (rpg->manager->event.type == sfEvtTextEntered) {
        if (rpg->manager->event.text.unicode > 31
        && rpg->manager->event.text.unicode < 128 && i < 26)
            write_name(rpg, c, idx, i);
    } else if (rpg->manager->event.key.code == sfKeyBack
        && rpg->manager->event.type == sfEvtKeyPressed)
            delete_char(rpg, idx, i);
    if (rpg->manager->event.key.code == sfKeyEnter
    && rpg->manager->event.type == sfEvtKeyReleased)
        enter_name(rpg, idx);
}
