/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Skip Action
*/

#include "my_macro.h"
#include "my_rpg.h"

void init_chatbox(chatbox_t *chat, char const *filepath);
int set_chatbox(my_rpg_t *rpg);

void skip(my_rpg_t *rpg)
{
    set_chatbox(rpg);
    if (rpg->game->quests < 6)
        rpg->game->quests += 1;
    rpg->game->is_in_dialog = 0;
}

void action_player_skip(my_rpg_t *rpg)
{
    if (rpg->manager->input->keys[KEY_SKIP_DIALOG]->status == true) {
        if (rpg->game->is_in_dialog == 1)
            skip(rpg);
    } else
        rpg->player->actions[KEY_SKIP_DIALOG].activate = false;
}
