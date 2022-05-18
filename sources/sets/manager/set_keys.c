/*
** EPITECH PROJECT, 2022
** set_keys.c
** File description:
** set_keys
*/

#include "my_rpg.h"
#include "my_macro.h"
#include <stdlib.h>

void set_the_key(my_key_t *key_struct, sfKeyCode key)
{
    key_struct->key = key;
    key_struct->status = sfFalse;
    return;
}

static void set_key_player(my_rpg_t *rpg)
{
    set_the_key(rpg->manager->input->keys[KEY_NORTH], sfKeyZ);
    set_the_key(rpg->manager->input->keys[KEY_SUD], sfKeyS);
    set_the_key(rpg->manager->input->keys[KEY_WEST], sfKeyQ);
    set_the_key(rpg->manager->input->keys[KEY_EAST], sfKeyD);
    set_the_key(rpg->manager->input->keys[KEY_SPRINT], sfKeyLShift);
    set_the_key(rpg->manager->input->keys[KEY_ATTACK], sfKeySpace);
    set_the_key(rpg->manager->input->keys[KEY_INTERACT], sfKeyE);
    set_the_key(rpg->manager->input->keys[KEY_SKIP_DIALOG], sfKeyC);
    set_the_key(rpg->manager->input->keys[KEY_LEAVE_HOUSE], sfKeyF);
    set_the_key(rpg->manager->input->keys[KEY_LEAVE_EXETERIOR], sfKeyF);
    set_the_key(rpg->manager->input->keys[KEY_INVENTORY_1], sfKeyNum1);
    set_the_key(rpg->manager->input->keys[KEY_INVENTORY_2], sfKeyNum2);
    set_the_key(rpg->manager->input->keys[KEY_INVENTORY_3], sfKeyNum3);
    set_the_key(rpg->manager->input->keys[KEY_INVENTORY_4], sfKeyQuote);
    set_the_key(rpg->manager->input->keys[KEY_INVENTORY_5], sfKeyNum5);
    set_the_key(rpg->manager->input->keys[KEY_INVENTORY_6], sfKeyHyphen);
    set_the_key(rpg->manager->input->keys[KEY_INVENTORY_7], sfKeyNum7);
    set_the_key(rpg->manager->input->keys[KEY_COMPETENCIES], sfKeyK);
    set_the_key(rpg->manager->input->keys[KEY_ESCAPE], sfKeyEscape);
    set_the_key(rpg->manager->input->keys[KEY_SPACE], sfKeySpace);
}

void set_keys(my_rpg_t *rpg)
{
    rpg->manager->input = malloc(sizeof(input_t));
    rpg->manager->input->keys = malloc(sizeof(my_key_t) * NB_KEYS);
    for (int i = 0; i != NB_KEYS; ++i)
        rpg->manager->input->keys[i] = malloc(sizeof(my_key_t));
    set_key_player(rpg);
    return;
}
