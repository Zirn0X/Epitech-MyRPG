/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** player_pause
*/

#include "my_rpg.h"
#include "my_macro.h"

void player_pause(my_rpg_t *rpg, sfEventType event, int key)
{
    if (event == sfEvtKeyPressed && key == KEY_ESCAPE &&
    rpg->scenes->sub_scenes != S_PAUSE)
        rpg->game->scenes = S_PAUSE;
    if (event == sfEvtKeyPressed && key == KEY_SPACE &&
    rpg->scenes->sub_scenes == S_PAUSE && rpg->pause->id == 1)
        rpg->game->scenes = rpg->current_sub;
    if (rpg->scenes->sub_scenes == S_PAUSE && rpg->pause->id == RESUME_OPT)
        rpg->scenes->sub_scenes = rpg->current_sub;
    if (event == sfEvtKeyPressed && key == KEY_SPACE &&
    rpg->scenes->sub_scenes == S_PAUSE && rpg->pause->id == QUIT_OPT)
        rpg->manager->end = QUIT;
    if (event == sfEvtKeyPressed && key == KEY_SPACE &&
    rpg->scenes->sub_scenes == S_PAUSE && rpg->pause->id == HOME_OPT) {
        sfRenderWindow_setView(rpg->manager->window, rpg->manager->view_home);
        rpg->scenes->type_scenes = TYPE_MENU;
        rpg->scenes->sub_scenes = HOME_PAGE;
    }
}
