/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Set ChatBox
*/

#include "my_rpg.h"
#include "my_macro.h"

void init_chatbox(chatbox_t *chat, char *filepath);

int set_chatbox(my_rpg_t *rpg)
{
    init_chatbox(&rpg->chatbox[CHATBOX_1], "assets/chatbox/text1");
    init_chatbox(&rpg->chatbox[CHATBOX_2], "assets/chatbox/text2");
    init_chatbox(&rpg->chatbox[CHATBOX_3], "assets/chatbox/text3");
    init_chatbox(&rpg->chatbox[CHATBOX_4], "assets/chatbox/text4");
    return (SUCCESS);
}
