/*
** EPITECH PROJECT, 2022
** window.c
** File description:
** window
*/

#include "my_rpg.h"
#include "my_macro.h"

int set_window(manager_t *manager)
{
    sfVideoMode video_mode = {1920, 1080, 64};
    manager->window =
    sfRenderWindow_create(video_mode, "My_RPG", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(manager->window, 60);
    return (SUCCESS);
}
