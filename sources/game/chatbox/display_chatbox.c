/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Display Chat box
*/

#include "my_rpg.h"
#include "my_chatbox.h"

static void change_text(chatbox_t *chat)
{
    if (chat->buffer[chat->pos] != '\0') {
        chat->text_cut[chat->pos] = chat->buffer[chat->pos];
        chat->text_cut[chat->pos + 1] = '\0';
        chat->pos++;
    }
}

void display_chatbox(my_rpg_t *rpg, chatbox_t *chat)
{
    chat->time = sfClock_getElapsedTime(chat->clock);
    chat->seconds = chat->time.microseconds / 1000.0;
    sfRenderWindow_drawSprite(rpg->manager->window, chat->s_box, sfFalse);
    if (chat->seconds > 5) {
        change_text(chat);
        sfText_setString(chat->text, chat->text_cut);
        sfClock_restart(chat->clock);
    }
    sfRenderWindow_drawText(rpg->manager->window, chat->text, sfFalse);
}
