/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Init chat box
*/

#include <stdlib.h>
#include <string.h>
#include "my_chatbox.h"
#include "my_rpg.h"
#include "my_lib.h"

void init_chatbox(chatbox_t *chat, char *filepath)
{
    int lines = 0;

    chat->buffer = read_file_wo_stat(filepath, &lines);
    chat->text = sfText_create();
    chat->box = sfRectangleShape_create();
    chat->font = sfFont_createFromFile("assets/harkham.ttf");
    chat->seconds = 0;
    chat->clock = sfClock_create();
    chat->text_cut = malloc(sizeof(char) * (strlen(chat->buffer) + 1));
    chat->text_cut[0] = '\0';
    chat->pos = 0;
    chat->s_box = sfSprite_create();
    chat->s_texure = sfTexture_createFromFile("assets/chatbox.png", NULL);
    chat->pos_box = (sfVector2f) {400, 720};
    sfSprite_setTexture(chat->s_box, chat->s_texure, sfFalse);
    sfSprite_setPosition(chat->s_box, chat->pos_box);
    sfText_setColor(chat->text, sfWhite);
    sfText_setFont(chat->text, chat->font);
    sfText_setString(chat->text, chat->buffer);
    sfText_setCharacterSize(chat->text, 25);
}
