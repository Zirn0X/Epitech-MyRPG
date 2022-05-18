/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Set Quests
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

static void create_quests(my_rpg_t *rpg, quest_t *quest, char *filepath)
{
    int lines = 0;

    quest->sprite = malloc(sizeof(my_sprite_t));
    quest->text = malloc(sizeof(text_t));

    quest->sprite->sprite = sfSprite_create();
    quest->sprite->texture = sfTexture_createFromFile("assets/quest.png", NULL);
    sfSprite_setTexture(quest->sprite->sprite, quest->sprite->texture, sfFalse);
    quest->content_file = read_file_wo_stat(filepath, &lines);
    quest->text->text = sfText_create();
    quest->text->font = sfFont_createFromFile("assets/harkham.ttf");
    sfText_setFont(quest->text->text, quest->text->font);
    sfText_setCharacterSize(quest->text->text, 20);
    sfText_setString(quest->text->text, quest->content_file);
    sfText_setColor(quest->text->text, sfBlack);
}

int set_quests(my_rpg_t *rpg)
{
    rpg->quests = malloc(sizeof(quest_t) * NB_QUESTS);

    create_quests(rpg, &rpg->quests[QUEST_1], "assets/quests/quest1");
    create_quests(rpg, &rpg->quests[QUEST_2], "assets/quests/quest2");
    create_quests(rpg, &rpg->quests[QUEST_3], "assets/quests/quest3");
    create_quests(rpg, &rpg->quests[QUEST_4], "assets/quests/quest4");
    create_quests(rpg, &rpg->quests[QUEST_5], "assets/quests/quest5");
    create_quests(rpg, &rpg->quests[QUEST_6], "assets/quests/quest6");
    create_quests(rpg, &rpg->quests[QUEST_7], "assets/quests/quest7");
    create_quests(rpg, &rpg->quests[QUEST_8], "assets/quests/quest8");
    create_quests(rpg, &rpg->quests[QUEST_9], "assets/quests/quest9");
    return (SUCCESS);
}