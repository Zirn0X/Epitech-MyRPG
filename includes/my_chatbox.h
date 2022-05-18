/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Chatbox Header file
*/

#ifndef CHATBOX_H
    #define CHATBOX_H
    #include "my_rpg.h"

void init_chatbox(chatbox_t *chat, char *filepath);
void display_chatbox(my_rpg_t *rpg, chatbox_t *chat);

#endif