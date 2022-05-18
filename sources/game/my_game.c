/*
** EPITECH PROJECT, 2022
** my_game.c
** File description:
** my_game
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "game/game_presets.h"
#include "map/read_map.h"
#include "my_macro.h"
#include "my_rpg.h"
#include "manager/my_input.h"
#include "game/player/player_objects.h"
#include "my_lib.h"
#include "player/player_competencies.h"

void actualise_map(my_rpg_t *rpg, int map, int layer, int csv);

void my_rpg_events(manager_t *manager, my_rpg_t *rpg)
{
    sfVector2f click_pos;

    if (manager->event.type == sfEvtMouseMoved) {
        rpg->home_menu->pos_mouse.x = manager->event.mouseMove.x;
        rpg->home_menu->pos_mouse.y = manager->event.mouseMove.y;
        sfSprite_setPosition(rpg->home_menu->sprite_cursor, (sfVector2f)
        {rpg->home_menu->pos_mouse.x, rpg->home_menu->pos_mouse.y});
    }
    if (manager->event.type == sfEvtClosed)
        sfRenderWindow_close(manager->window);
    if (rpg->scenes->type_scenes != TYPE_MENU) {
        get_input(rpg);
    }
    rpg->scenes->events[rpg->scenes->type_scenes][rpg->scenes->sub_scenes]
    (rpg);
    // if (rpg->scenes->type_scenes == TYPE_GAME && rpg->scenes->sub_scenes ==
    // S_MANOIR)
    //     sfSprite_setScale(rpg->player->player, (sfVector2f) {1, 1});
    return;
}

void display_cursor(sfRenderWindow *window, interface_t *home)
{
    sfRenderWindow_drawSprite(window, home->sprite_cursor, NULL);
}

static void game_events(manager_t *manager, my_rpg_t *rpg)
{
    sfVector2f click_pos;

    if (manager->event.type == sfEvtClosed)
        sfRenderWindow_close(manager->window);
    return;
}

void update_time(delta_time_t *dt)
{
    dt->curr = sfClock_getElapsedTime(dt->clock);
    dt->time = (dt->curr.microseconds - dt->last.microseconds) / 1000000.0f;
    dt->last = dt->curr;
    return;
}

int my_game(my_rpg_t *rpg)
{
    srand(getpid());
    actualise_map(rpg, S_EXTERIORS, EXTERIORS_LAYER, CSV_EXTERIORS);
    add_object_player(rpg, rpg->all_objects->lantern, 0);
    rpg->player->tuile_x = find_player_pos(rpg->player->sprite->position.x, rpg->maps->csv[CSV_MANOIR].len_csv_line, 32.0);
    rpg->player->tuile_y = find_player_pos(rpg->player->sprite->position.y, rpg->maps->csv[CSV_MANOIR].len_csv, 32.0);
    rpg->maps->csv[CSV_EXTERIORS].colision[rpg->player->tuile_y][rpg->player->tuile_x] = 0;
    while (sfRenderWindow_isOpen(rpg->manager->window)) {
        update_time(rpg->manager->dt);
        sfRenderWindow_display(rpg->manager->window);
        sfRenderWindow_clear(rpg->manager->window, sfBlack);
        rpg->scenes->scenes[rpg->scenes->type_scenes][rpg->scenes->sub_scenes]
        (rpg);
        display_cursor(rpg->manager->window, rpg->home_menu);
        while (sfRenderWindow_pollEvent(rpg->manager->window,
        &rpg->manager->event))
            my_rpg_events(rpg->manager, rpg);
        if (rpg->manager->end == -1)
            break;
    }
    return (SUCCESS);
}