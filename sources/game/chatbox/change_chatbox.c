/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Change Chatbox
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "objects/object_utils.h"

void display_chatbox(my_rpg_t *rpg, chatbox_t *chat);

static void set_pos_chatbox(my_rpg_t *rpg)
{
    rpg->chatbox[1].pos_box = rpg->player->sprite->position;
    sfSprite_setPosition(rpg->chatbox[1].s_box, (sfVector2f)
    {rpg->chatbox[1].pos_box.x - 550, rpg->chatbox[1].pos_box.y + 190});
    sfText_setPosition(rpg->chatbox[1].text, (sfVector2f)
    {rpg->chatbox[1].pos_box.x - 420, rpg->chatbox[1].pos_box.y + 250});
    rpg->chatbox[0].pos_box = rpg->player->sprite->position;
    sfSprite_setPosition(rpg->chatbox[0].s_box, (sfVector2f)
    {rpg->chatbox[0].pos_box.x - 550, rpg->chatbox[0].pos_box.y + 190});
    sfText_setPosition(rpg->chatbox[0].text, (sfVector2f)
    {rpg->chatbox[0].pos_box.x - 420, rpg->chatbox[0].pos_box.y + 250});
    rpg->chatbox[2].pos_box = rpg->player->sprite->position;
    sfSprite_setPosition(rpg->chatbox[2].s_box, (sfVector2f)
    {rpg->chatbox[2].pos_box.x - 550, rpg->chatbox[2].pos_box.y + 190});
    sfText_setPosition(rpg->chatbox[2].text, (sfVector2f)
    {rpg->chatbox[2].pos_box.x - 420, rpg->chatbox[2].pos_box.y + 250});
    rpg->chatbox[3].pos_box = rpg->player->sprite->position;
    sfSprite_setPosition(rpg->chatbox[3].s_box, (sfVector2f)
    {rpg->chatbox[3].pos_box.x - 550, rpg->chatbox[3].pos_box.y + 190});
    sfText_setPosition(rpg->chatbox[3].text, (sfVector2f)
    {rpg->chatbox[3].pos_box.x - 420, rpg->chatbox[3].pos_box.y + 250});
}


void change_chatbox(my_rpg_t *rpg)
{
    set_pos_chatbox(rpg);
    if (rpg->game->current_dialog == CHATBOX_1 && rpg->game->quests == QUEST_2)
        display_chatbox(rpg, &rpg->chatbox[CHATBOX_1]);
    if (rpg->game->current_dialog == CHATBOX_2 && rpg->game->quests == QUEST_4) {
        display_chatbox(rpg, &rpg->chatbox[CHATBOX_2]);
        for (int i = 0; i < NB_PLAYER_OBJECTS; i++)
            if (rpg->player->inventory->rectangle[i].obj->flag == 'M')
                delete_from_inventory(rpg, i);
    }
    if (rpg->game->current_dialog == CHATBOX_3 && rpg->game->quests == QUEST_6) {
        display_chatbox(rpg, &rpg->chatbox[CHATBOX_3]);
        for (int i = 0; i < NB_PLAYER_OBJECTS; i++)
            if (rpg->player->inventory->rectangle[i].obj->flag == 'P')
                delete_from_inventory(rpg, i);
    }
    if (rpg->game->current_dialog == 3 && rpg->game->quests == 7)
        display_chatbox(rpg, &rpg->chatbox[CHATBOX_4]);
}
