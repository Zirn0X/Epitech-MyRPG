/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** utils_save
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void set_texture_sprite(sfSprite **sprite, sfTexture *texture,
char *file_texture, sfIntRect rect);
void movement_player(my_rpg_t *rpg);
void actualise_map(my_rpg_t *rpg, int map, int layer, int csv);

void hover_save(my_rpg_t *rpg, sfVector2f pos_mouse, int i)
{
    int greater_min_x = pos_mouse.x >= rpg->home_save->button[i]->hit_min.x;
    int lower_max_x = pos_mouse.x <= rpg->home_save->button[i]->hit_max.x;
    int greater_min_y = pos_mouse.y >= rpg->home_save->button[i]->hit_min.y;
    int lower_max_y = pos_mouse.y <= rpg->home_save->button[i]->hit_max.y;

    if (i == 6) {
        if (greater_min_x && lower_max_x && greater_min_y && lower_max_y)
            rpg->home_save->button[i]->rect.left =
            rpg->home_save->button[i]->rect.width;
        else
            rpg->home_save->button[i]->rect.left = 0;
    }
    if (i > 6 && i < 10 && rpg->player->id != NO_ONE) {
        if (greater_min_x && lower_max_x && greater_min_y && lower_max_y)
            rpg->home_save->button[i]->rect.left =
            rpg->home_save->button[i]->rect.width * 2;
        else
            rpg->home_save->button[i]->rect.left =
            rpg->home_save->button[i]->rect.width;
    }
}

static void set_outline(my_rpg_t *rpg, int i)
{
    sfRectangleShape_setOutlineThickness(rpg->home_save->button[3]->button, 0);
    sfRectangleShape_setOutlineThickness(rpg->home_save->button[4]->button, 0);
    sfRectangleShape_setOutlineThickness(rpg->home_save->button[5]->button, 0);
    sfRectangleShape_setOutlineThickness(rpg->home_save->button[i]->button, 5);
    sfRectangleShape_setOutlineColor(rpg->home_save->button[i]->button, sfRed);
    rpg->player->id = i - 2;
}

static void unset_outline(my_rpg_t *rpg)
{
    sfRectangleShape_setOutlineThickness(rpg->home_save->button[3]->button, 0);
    sfRectangleShape_setOutlineThickness(rpg->home_save->button[4]->button, 0);
    sfRectangleShape_setOutlineThickness(rpg->home_save->button[5]->button, 0);
    rpg->player->id = NO_ONE;
    rpg->home_save->button[7]->rect.left = 0;
    rpg->home_save->button[8]->rect.left = 0;
    for (int i = 7; i != 9; i++)
        sfRectangleShape_setTextureRect(rpg->home_save->button[i]->button,
        rpg->home_save->button[i]->rect);
}

static void set_spritesheet(my_rpg_t *rpg)
{
    char *assets = malloc(sizeof(char) * 23);

    if (rpg->player->id == FIRST)
        assets = "assets/player/hero.png";
    if (rpg->player->id == SECOND)
        assets = "assets/player/hero2.png";
    if (rpg->player->id == THIRD)
        assets = "assets/player/hero3.png";
    set_texture_sprite(&(rpg->player->sprite->sprite),
    rpg->all_texture->player_txt, assets, rpg->player->sprite->rect);
    sfSprite_scale(rpg->player->sprite->sprite, (sfVector2f) {2.5, 2.5});
}

void get_case_save(my_rpg_t *rpg, int i)
{
    int cond = 0;

    if (rpg->player->id != NO_ONE)
        cond = (rpg->home_save->name[rpg->player->id - 1].changable
        == NOT_CHANGABLE);
    for (int j = 3; j != 6; j++)
        if (i == j)
            set_outline(rpg, i);
    if (i == GO_HOME) {
        unset_outline(rpg);
        rpg->scenes->sub_scenes = HOME_PAGE;
    }
    if (i == START_GAME && rpg->player->id != NO_ONE && cond) {
        sfMusic_stop(rpg->home_menu->music);
        set_spritesheet(rpg);
        rpg->scenes->type_scenes = TYPE_GAME;
        rpg->current_sub = S_MANOIR;
        rpg->scenes->sub_scenes = rpg->current_sub;
        actualise_map(rpg, S_MANOIR, MANOIR_LAYERS, CSV_MANOIR);
    }
}
