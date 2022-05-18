/*
** EPITECH PROJECT, 2022
** set_camera.c
** File description:
** set_camera
*/

#include "my_rpg.h"
#include "my_macro.h"

int set_home_camera(my_rpg_t *rpg)
{
    rpg->manager->view_home = sfView_create();
    rpg->manager->view_home =
    (sfView *) sfRenderWindow_getDefaultView(rpg->manager->window);
}

int set_camera(my_rpg_t *rpg)
{
    rpg->manager->camera = sfView_copy(sfRenderWindow_getView
    (rpg->manager->window));
    sfView_zoom(rpg->manager->camera, 0.8);
    sfView_setCenter(rpg->manager->camera, (sfVector2f)
    {rpg->player->sprite->position.x + (rpg->player->size_x / 2),
    rpg->player->sprite->position.y + (rpg->player->size_y / 2)});
    // sfRenderWindow_setView(rpg->manager->window, rpg->manager->camera);
    return (SUCCESS);
}