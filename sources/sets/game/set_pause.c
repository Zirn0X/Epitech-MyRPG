/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_pause
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"

void set_string_pos(my_rpg_t *rpg)
{
    sfText_setPosition(rpg->pause->name[0].text,
    (sfVector2f) {rpg->player->sprite->position.x - 200, rpg->player->sprite->position.y - 300});
    sfText_setPosition(rpg->pause->name[1].text,
    (sfVector2f) {rpg->player->sprite->position.x - 580, rpg->player->sprite->position.y + 100});
    sfText_setPosition(rpg->pause->name[2].text,
    (sfVector2f) {rpg->player->sprite->position.x - 80, rpg->player->sprite->position.y + 100});
    sfText_setPosition(rpg->pause->name[3].text,
    (sfVector2f) {rpg->player->sprite->position.x + 420, rpg->player->sprite->position.y + 100});
}

static int set_string_pause(my_rpg_t *rpg)
{
    char *string[] = {"PAUSE MENU", "QUIT", "RESUME", "HOME_MENU"};

    rpg->pause = malloc(sizeof(interface_t));
    if (rpg->pause == NULL)
        return (ERROR);
    rpg->pause->name = malloc(sizeof(text_t) * 4);
    for (int i = 0; i != 4; i++) {
        rpg->pause->name[i].text = sfText_create();
        rpg->pause->name[i].font = sfFont_createFromFile("assets/breathe.ttf");
        sfText_setString(rpg->pause->name[i].text, string[i]);
        sfText_setFont(rpg->pause->name[i].text, rpg->pause->name[i].font);
        sfText_setColor(rpg->pause->name[i].text, sfWhite);
    }
    sfText_setCharacterSize(rpg->pause->name[0].text, 100);
    sfText_setCharacterSize(rpg->pause->name[1].text, 50);
    sfText_setCharacterSize(rpg->pause->name[2].text, 50);
    sfText_setCharacterSize(rpg->pause->name[3].text, 50);
    set_string_pos(rpg);
}

void set_pos_texture(my_rpg_t *rpg)
{
    if (rpg->pause->id == 0)
        sfSprite_setPosition(rpg->pause->sprite_cursor,
        (sfVector2f) {rpg->player->sprite->position.x - 470, rpg->player->sprite->position.y + 90});
    if (rpg->pause->id == 1)
        sfSprite_setPosition(rpg->pause->sprite_cursor,
        (sfVector2f) {rpg->player->sprite->position.x + 100, rpg->player->sprite->position.y + 90});
    if (rpg->pause->id == 2)
        sfSprite_setPosition(rpg->pause->sprite_cursor,
        (sfVector2f) {rpg->player->sprite->position.x + 650, rpg->player->sprite->position.y + 90});
}

static void set_sprite_pause(my_rpg_t *rpg)
{
    rpg->pause->sprite_cursor = sfSprite_create();
    rpg->pause->texture_cursor =
    sfTexture_createFromFile("assets/cursor2.png", NULL);
    sfSprite_setTexture
    (rpg->pause->sprite_cursor, rpg->pause->texture_cursor, sfFalse);
    sfSprite_setScale(rpg->pause->sprite_cursor, (sfVector2f) {3, 3});
    set_pos_texture(rpg);
}

int set_pause(my_rpg_t *rpg)
{
    if (set_string_pause(rpg) == ERROR)
        return (ERROR);
    rpg->pause->id = 1;
    set_sprite_pause(rpg);
    return (SUCCESS);
}
