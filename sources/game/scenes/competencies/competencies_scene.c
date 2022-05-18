/*
** EPITECH PROJECT, 2022
** Rpg
** File description:
** Competencies scene
*/

#include "my_rpg.h"
#include "my_lib.h"
#include "my_macro.h"
#include "manager/my_input.h"
#include "game/game_events.h"

static void set_pos_sprites(my_rpg_t *rpg)
{
    sfSprite_setPosition(rpg->menu_competencies->s_competencies[0].sprite,
    (sfVector2f) {rpg->player->sprite->position.x - 350, rpg->player->sprite->position.y - 200});
    sfSprite_setPosition(rpg->menu_competencies->s_competencies[1].sprite,
    (sfVector2f) {rpg->player->sprite->position.x - 270, rpg->player->sprite->position.y - 90});
    sfSprite_setPosition(rpg->menu_competencies->s_competencies[2].sprite,
    (sfVector2f) {rpg->player->sprite->position.x - 270, rpg->player->sprite->position.y + 90});
    sfSprite_setPosition(rpg->menu_competencies->s_competencies[3].sprite,
    (sfVector2f) {rpg->player->sprite->position.x + 90, rpg->player->sprite->position.y - 90});
    sfSprite_setPosition(rpg->menu_competencies->s_competencies[4].sprite,
    (sfVector2f) {rpg->player->sprite->position.x + 90, rpg->player->sprite->position.y + 90});
}

static void set_pos_text(my_rpg_t *rpg)
{
    rpg->menu_competencies->t_competencies[0].position = (sfVector2f)
    {rpg->player->sprite->position.x - 70, rpg->player->sprite->position.y - 270};
    rpg->menu_competencies->t_competencies[1].position = (sfVector2f)
    {rpg->player->sprite->position.x + 90, rpg->player->sprite->position.y - 270};
    rpg->menu_competencies->t_competencies[2].position = (sfVector2f)
    {rpg->player->sprite->position.x - 170, rpg->player->sprite->position.y - 90};
    rpg->menu_competencies->t_competencies[3].position = (sfVector2f)
    {rpg->player->sprite->position.x - 170, rpg->player->sprite->position.y + 90};
    rpg->menu_competencies->t_competencies[4].position = (sfVector2f)
    {rpg->player->sprite->position.x + 190, rpg->player->sprite->position.y - 90};
    rpg->menu_competencies->t_competencies[5].position = (sfVector2f)
    {rpg->player->sprite->position.x + 190, rpg->player->sprite->position.y + 90};
    for (int i = 0; i < 6; i++)
        sfText_setPosition(rpg->menu_competencies->t_competencies[i].text,
        rpg->menu_competencies->t_competencies[i].position);
}

static void set_pos_rect(my_rpg_t *rpg)
{
    if (rpg->player->compentencies->id == 0) {
        rpg->menu_competencies->b_competencies[0].pos = (sfVector2f)
        {rpg->player->sprite->position.x - 120, rpg->player->sprite->position.y - 90};
    }
    if (rpg->player->compentencies->id == 1) {
        rpg->menu_competencies->b_competencies[0].pos = (sfVector2f)
        {rpg->player->sprite->position.x - 120, rpg->player->sprite->position.y + 90};
    }
    if (rpg->player->compentencies->id == 2) {
        rpg->menu_competencies->b_competencies[0].pos = (sfVector2f)
        {rpg->player->sprite->position.x + 240, rpg->player->sprite->position.y - 90};
    }
    if (rpg->player->compentencies->id == 3) {
        rpg->menu_competencies->b_competencies[0].pos = (sfVector2f)
        {rpg->player->sprite->position.x + 240, rpg->player->sprite->position.y + 90};
    }
    sfRectangleShape_setPosition
    (rpg->menu_competencies->b_competencies[0].button,
    rpg->menu_competencies->b_competencies[0].pos);
}

static void draw_alls(my_rpg_t *rpg)
{
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawSprite(rpg->manager->window,
                                  rpg->menu_competencies->
                                  s_competencies[i].sprite, sfFalse);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawText(rpg->manager->window,rpg->menu_competencies->
        t_competencies[i].text, sfFalse);
    sfRenderWindow_drawRectangleShape(rpg->manager->window,
    rpg->menu_competencies->b_competencies[0].button, sfFalse);
}

int competencies_scene(my_rpg_t *rpg)
{
    set_pos_sprites(rpg);
    set_pos_text(rpg);
    set_pos_rect(rpg);
    sfText_setString(rpg->menu_competencies->t_competencies[0].text,
                     "Total Points :");
    sfText_setString(rpg->menu_competencies->t_competencies[1].text,
                     my_itoa(rpg->player->compentencies->points));
    sfText_setString(rpg->menu_competencies->t_competencies[2].text,
                     my_itoa(rpg->player->compentencies->resistance));
    sfText_setString(rpg->menu_competencies->t_competencies[3].text,
                     my_itoa(rpg->player->compentencies->attack));
    sfText_setString(rpg->menu_competencies->t_competencies[4].text,
                     my_itoa(rpg->player->compentencies->life));
    sfText_setString(rpg->menu_competencies->t_competencies[5].text,
                     my_itoa(rpg->player->compentencies->speed));
    draw_alls(rpg);
    return SUCCESS;
}
